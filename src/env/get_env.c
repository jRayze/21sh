/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:16:59 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:17:01 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"
#include "../builtin/builtin.h"

char		*get_specific_env(char *env, t_env **envlist)
{
	t_env	*cp;

	if ((cp = (*envlist)))
	{
		while (cp)
		{
			if (ft_strncmp(env, cp->env, ft_strlen(env)) == 0)
			{
				if (!cp->env[ft_strlen(env)] || ft_strlen(cp->env) > 2048)
					return (NULL);
				return (ft_strdup(&cp->env[ft_strlen(env)]));
			}
			cp = cp->next;
		}
	}
	return (NULL);
}

char		*get_specific_loc(char *env, t_loc **envlist)
{
	t_loc	*cp;

	if (env && env[0] == '?' && env[1] == '=' && !env[2])
		return (ft_itoa(g_sh->retval));
	if ((cp = (*envlist)))
	{
		while (cp)
		{
			if (ft_strncmp(env, cp->content, ft_strlen(env)) == 0)
			{
				if (!cp->content[ft_strlen(env)])
					return (NULL);
				return (ft_strdup(&cp->content[ft_strlen(env)]));
			}
			cp = cp->next;
		}
	}
	return (NULL);
}

void		set_pwd_env(t_sh *sh)
{
	char *pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 2048);
	set_env(&sh->env, "PWD=", pwd);
	free(pwd);
}

void		get_env(char **env, t_sh *sh)
{
	int		i;
	char	*shlvl;
	char	*setenv[2];
	int		shlvl_atoi;

	i = -1;
	sh->env = NULL;
	while (env[++i])
		if (ft_strlen(env[i]) < 20000)
			env_push_back(&sh->env, env[i]);
	if ((shlvl = get_specific_env("SHLVL=", &sh->env)))
	{
		shlvl_atoi = ft_atoi(shlvl);
		free(shlvl);
		setenv[0] = ft_strdup("SHLVL=");
		setenv[1] = ft_itoa(shlvl_atoi + 1);
		set_env(&sh->env, setenv[0], setenv[1]);
		free(setenv[0]);
		free(setenv[1]);
	}
	else
		env_push_back(&sh->env, "SHLVL=1");
	set_pwd_env(sh);
}
