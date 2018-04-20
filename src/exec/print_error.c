/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:21:11 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:21:12 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	errexit(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	print_err(int err, char *path)
{
	ft_putstr_fd("21sh: ", 2);
	ft_putstr_fd(path, 2);
	if (err == 1)
		ft_putstr_fd(": No such file or directory\n", 2);
	if (err == 2)
		ft_putstr_fd(": Command not found\n", 2);
	if (err == 3)
		ft_putstr_fd(": Command not found\n", 2);
	if (err == 4)
		ft_putstr_fd(": Is a directory\n", 2);
}

void	print_access_error(char *fullpath)
{
	if (access(fullpath, X_OK))
		ft_putstr_fd("Permission denied\n", 2);
	else
	{
		ft_putstr_fd("21sh: ", 2);
		ft_putstr_fd(fullpath, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}
