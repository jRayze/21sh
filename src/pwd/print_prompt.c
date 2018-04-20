/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:29:08 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:29:10 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void		prompt_colors(int i)
{
	if (i == 1)
		ft_putstr("\x1b[36m");
	if (i == 2)
		ft_putstr("\x1b[32m");
	if (i == 3)
		ft_putstr("\x1b[31m");
	if (i == 0)
		ft_putstr("\x1b[0m");
}

void		tild_prompt(t_sh *sh)
{
	if (ft_strncmp(sh->home_env, sh->pwd, ft_strlen(sh->home_env)) == 0)
	{
		sh->posy += ft_strlen(&sh->pwd[ft_strlen(sh->home_env)]) + 1;
		ft_putchar('~');
		ft_putstr(&sh->pwd[ft_strlen(sh->home_env)]);
	}
	else
	{
		sh->posy += ft_strlen(sh->pwd);
		ft_putstr(sh->pwd);
	}
	free(sh->home_env);
}

void		try_pwd(t_sh *sh)
{
	char	buff[PATH_MAX];
	char	*path;

	if ((path = get_specific_env("PWD=", &sh->env)))
	{
		ft_strcat(sh->pwd, path);
		free(path);
	}
	else
	{
		getcwd(buff, PATH_MAX);
		ft_strcat(sh->pwd, buff);
	}
}

void		print_prompt(t_sh *sh)
{
	ft_bzero(sh->pwd, 2048);
	try_pwd(sh);
	sh->posy = 4;
	prompt_colors(1);
	sh->width = tgetnum("co");
	if ((sh->home_env = get_specific_env("HOME=", &sh->env)))
		tild_prompt(sh);
	else
	{
		sh->posy += ft_strlen(sh->pwd);
		ft_putstr(sh->pwd);
	}
	if (sh->retval == 0)
		prompt_colors(2);
	else
		prompt_colors(3);
	ft_putstr(" » ");
	prompt_colors(0);
	sh->prompt_len = sh->posy;
	if (sh->prompt_len > sh->width)
		sh->posy = sh->prompt_len % sh->width;
}
