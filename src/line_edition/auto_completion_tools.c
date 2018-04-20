/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 21:26:44 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 21:26:44 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int			preview_autocompletion(t_sh *sh, t_inp *cp, int which)
{
	int		escape;

	escape = 0;
	while (which && cp)
	{
		sh->dec++;
		ft_putchar(cp->c);
		check_endline(sh);
		cp = cp->next;
	}
	while (!which && sh->comp_remain[++sh->dec])
	{
		if (escape_char(sh->comp_remain[sh->dec]))
		{
			ft_putchar('\\');
			sh->dec++;
			check_endline(sh);
			escape++;
		}
		ft_putchar(sh->comp_remain[sh->dec]);
		check_endline(sh);
	}
	return (escape);
}

void		add_builtin_completion(t_sh *sh)
{
	bin_push_front(&sh->bin, "history");
	bin_push_front(&sh->bin, "myman");
	bin_push_front(&sh->bin, "color");
	bin_push_front(&sh->bin, "cd");
	bin_push_front(&sh->bin, "setenv");
	bin_push_front(&sh->bin, "unsetenv");
	bin_push_front(&sh->bin, "env");
	bin_push_front(&sh->bin, "set");
	bin_push_front(&sh->bin, "unset");
	bin_push_front(&sh->bin, "export");
	bin_push_front(&sh->bin, "local");
	bin_push_front(&sh->bin, "exit");
	bin_push_front(&sh->bin, "echo");
}

void		check_if_dir(t_sh *sh, t_inp **inp)
{
	char		buff[5000];
	struct stat	st;

	ft_bzero(buff, 5000);
	ft_strcat(buff, sh->save_path);
	if (buff[ft_strlen(buff) - 1] != '/')
		ft_strcat(buff, "/");
	ft_strcat(buff, sh->comp_debug);
	ft_strcat(buff, sh->comp_remain);
	if (lstat(buff, &st) != -1)
	{
		if (S_ISDIR(st.st_mode))
		{
			inp_insert_posat(inp, '/');
			ft_putchar('/');
			check_endline(sh);
		}
	}
}

void		insert_completion(t_sh *sh, t_inp **inp)
{
	t_inp	*cp;
	int		i;

	if (sh->comp_remain)
	{
		if ((cp = get_to_pos(inp)))
		{
			i = -1;
			while (sh->comp_remain[++i])
			{
				if (escape_char(sh->comp_remain[i]))
				{
					ft_putchar('\\');
					inp_insert_posat(&sh->inpl->inp, '\\');
					check_endline(sh);
				}
				inp_insert_posat(&sh->inpl->inp, sh->comp_remain[i]);
				ft_putchar(sh->comp_remain[i]);
				check_endline(sh);
			}
			check_if_dir(sh, inp);
			overwrite_remaining(sh, &sh->inpl->inp);
		}
		free_comp(3, sh);
	}
}
