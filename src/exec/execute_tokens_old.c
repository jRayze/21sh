/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tokens_old.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:17:37 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 19:04:51 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"
#include "../builtin/builtin.h"

char		*concat_command_path(char *path, char *command)
{
	char	*ret;
	int		len;

	ret = NULL;
	len = ft_strlen(path) + ft_strlen(command) + 1;
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(ret, len);
	ft_strcat(ret, path);
	ft_strcat(ret, "/");
	ft_strcat(ret, command);
	return (ret);
}

char		*find_command_path(char **path, char *command)
{
	char			*ret;
	DIR				*od;
	struct dirent	*fl;
	int				i;

	i = -1;
	ret = NULL;
	while (path[++i])
	{
		if ((od = opendir(path[i])))
		{
			while ((fl = readdir(od)))
			{
				if (ft_strcmp(command, fl->d_name) == 0)
				{
					closedir(od);
					return (concat_command_path(path[i], command));
				}
			}
			closedir(od);
		}
	}
	return (ret);
}

char		*check_path_bin(char *path, t_sh *sh)
{
	struct stat		data;

	if (access(path, F_OK) != 0)
		print_err(1, path);
	else if (access(path, X_OK) != 0)
		print_err(2, path);
	else if (stat(path, &data) == -1)
		print_err(3, path);
	else if (!(S_ISREG(data.st_mode)))
		print_err(4, path);
	else
		return (ft_strdup(path));
	sh->retval = 127;
	return (NULL);
}

char		*command_path(t_env **env, char *command, t_sh *sh)
{
	char			*path;
	char			*ret;
	char			**split;

	ret = NULL;
	if (command[0] == '/' || command[0] == '.')
		return (check_path_bin(command, sh));
	if ((path = get_hash_path(&sh->hash, command, sh)))
		return (ft_strdup(path));
	if ((path = get_specific_env("PATH=", env)))
	{
		if ((split = ft_strsplit(path, ':')))
		{
			ret = find_command_path(split, command);
			env_free(split);
		}
		free(path);
	}
	if (!ret)
	{
		print_err(2, command);
		sh->retval = 127;
	}
	return (ret);
}

void		free_char_array(char **array)
{
	int				i;

	i = -1;
	if (array)
	{
		while (array[++i])
			free(array[i]);
		if (array)
			free(array);
		array = NULL;
	}
}
