/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:17:42 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:17:42 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"
#include "../builtin/builtin.h"

char		**env_list_to_char(t_env **env)
{
	char	**ret;
	int		len;
	t_env	*cp;

	ret = NULL;
	len = 0;
	if ((cp = (*env)))
	{
		while (cp && ++len)
			cp = cp->next;
		if (!(ret = (char**)malloc(sizeof(char*) * (len + 1))))
			return (NULL);
		ret[len] = NULL;
		cp = (*env);
		len = 0;
		while (cp)
		{
			ret[len++] = ft_strdup(cp->env);
			cp = cp->next;
		}
	}
	return (ret);
}

int			fork_command(char *path, char **exec, char **env)
{
	pid_t	pid;
	int		status;

	status = -1;
	if ((pid = fork()) == 0)
	{
		signal_exec();
		execve(path, exec, env);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, WUNTRACED);
	signal_init();
	if (WIFSIGNALED(status) && WTERMSIG(status) == 2)
		ft_putstr("\n");
	return (status);
}
