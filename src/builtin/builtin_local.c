/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_local.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:12:06 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:12:06 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"
#include "builtin.h"

int		builtin_local(char **exec, t_sh *sh)
{
	t_loc	*cp;

	if (exec[1])
	{
		ft_putendl_fd("local: Too many arguments.", 2);
		return (1);
	}
	cp = sh->loc;
	while (cp)
	{
		ft_putendl(cp->content);
		cp = cp->next;
	}
	return (0);
}
