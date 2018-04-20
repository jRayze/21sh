/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:43:58 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 19:43:59 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"
#include "builtin.h"

int			no_argument(char **exec, int index)
{
	if (!exec[index])
		return (1);
	else if (ft_strcmp(exec[index], "-L") == 0 && !exec[index + 1])
		return (1);
	else if (ft_strcmp(exec[index], "-P") == 0 && !exec[index + 1])
		return (1);
	return (0);
}

int			change_pwd(int flag, t_env **env, char *path, int err)
{
	char	*oldpwd;
	int		ret;
	char	getpwd[2048];

	oldpwd = get_specific_env("PWD=", env);
	if (err == 1)
	{
		free(oldpwd);
		return (err_msg("cd: no such file or directory: ", getpwd, -1));
	}
	if (oldpwd)
		set_env(env, "OLDPWD=", oldpwd);
	ret = chdir(path);
	if (flag & 1)
		set_env(env, "PWD=", getcwd(getpwd, 2048));
	else
		set_env(env, "PWD=", path);
	free(oldpwd);
	return (ret);
}
