/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exclaim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:13:28 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:13:28 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"
#include "../../inc/header.h"

int			valid_last(t_inp *inp)
{
	if (!inp || inp->c == ' ')
		return (1);
	return (0);
}

int			valid_by_last(t_inp **inp)
{
	t_inp	*cp;

	if ((cp = (*inp)))
	{
		ft_putchar(cp->c);
	}
	return (0);
}
