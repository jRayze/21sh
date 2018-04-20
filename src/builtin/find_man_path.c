/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_man_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:15:19 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:15:20 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"
#include "./builtin.h"

char		*find_current(char *relative)
{
	char	*ret;
	char	buff[2048];

	ret = NULL;
	getcwd(buff, 2048);
	ft_strncat(buff, &relative[1], ft_strlen(relative) - 5);
	ft_strcat(buff, "src/man/");
	ret = ft_strdup(buff);
	return (ret);
}

char		*find_absolute(char *relative)
{
	char	*ret;
	int		len;

	ret = NULL;
	len = 0;
	len += ft_strlen(relative) + 4;
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(ret, len);
	ft_strncat(ret, relative, ft_strlen(relative) - 5);
	ft_strcat(ret, "/src/man/");
	return (ret);
}

char		*find_man_path(char *relative)
{
	if (relative[0] == '.' && relative[1] != '.')
		return (find_current(relative));
	else if (relative[0] == '/')
		return (find_absolute(relative));
	return (NULL);
}
