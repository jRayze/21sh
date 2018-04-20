/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:21:19 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:21:20 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	left_redirect(t_listc *cmd, t_pipe *tabtube, int i)
{
	int ret;

	if ((ret = open(cmd->redirs->file, O_RDONLY)) == -1)
	{
		ft_putstr_fd("21sh: no such file or directory: ", 2);
		ft_putendl_fd(cmd->redirs->file, 2);
		g_sh->err = 1;
	}
	tabtube[i].cote[0] = (cmd->redirs->file) ? ret : cmd->redirs->redir[0];
	tabtube[i].cote[1] = cmd->redirs->redir[2];
}

void	right_redirect(t_listc *cmd, t_pipe *tabtube, int i)
{
	tabtube[i].cote[0] = (cmd->redirs->file) ? open(cmd->redirs->file, O_RDWR
			| O_TRUNC | O_CREAT, S_IRWXU) : cmd->redirs->redir[2];
	tabtube[i].cote[1] = cmd->redirs->redir[0];
}

void	heredock_redirect(t_listc *cmd, t_pipe *tabtube, int i)
{
	int		j;
	t_redir *cp;

	j = 0;
	cp = cmd->redirs;
	if (pipe(tabtube[i].cote) == -1)
		errexit("Pipe failed.");
	while (cmd->redirs->heredoc[j])
	{
		write(tabtube[i].cote[1], cmd->redirs->heredoc[j]
			, ft_strlen(cmd->redirs->heredoc[j]));
		j++;
	}
	close(tabtube[i].cote[1]);
}

void	double_right_redirect(t_listc *cmd, t_pipe *tabtube, int i)
{
	tabtube[i].cote[0] = (cmd->redirs->file) ? open(cmd->redirs->file, O_RDWR
			| O_APPEND | O_CREAT, S_IRWXU) : cmd->redirs->redir[2];
	tabtube[i].cote[1] = cmd->redirs->redir[0];
}

void	redirect(t_listc *cmd, t_pipe *tabtube, int i, t_redir **redir)
{
	t_redir	*cp;

	cp = *redir;
	while (cmd->redirs != NULL)
	{
		if (cmd->redirs->redir[1] == 0)
			left_redirect(cmd, tabtube, i);
		else if (cmd->redirs->redir[1] == 1 || cmd->redirs->redir[1] == 16)
			right_redirect(cmd, tabtube, i);
		else if (cmd->redirs->redir[1] == 3)
			double_right_redirect(cmd, tabtube, i);
		else if (cmd->redirs->redir[1] & (AGGR | LAGGR | LAGGRIN | CLOSEAGGR))
			do_aggre(cmd, tabtube, i);
		if (g_sh->err == 1)
			break ;
		if (tabtube[i].cote[0] != -1)
			dup_fd(cmd, tabtube, i);
		if (!(cmd->redirs->redir[1] & AGGR))
			close(tabtube[i].cote[0]);
		if (!cmd->redirs->next)
			break ;
		cmd->redirs = cmd->redirs->next;
	}
	cmd->redirs = cp;
	i++;
}
