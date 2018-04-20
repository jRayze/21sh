/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclaim_misc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:14:55 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:14:56 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../../inc/header.h"

void	suppr_letter(t_inp **c)
{
	t_inp	*tmp;

	tmp = *c;
	if (tmp->previous)
	{
		tmp->previous->next = tmp->next;
		if (tmp->next)
			tmp->next->previous = tmp->previous;
		free(tmp);
	}
	else
	{
		tmp = (*c)->next;
		free(*c);
		if (tmp)
			(tmp)->previous = NULL;
	}
}

t_inp	*insert_inp(t_inp **inp, char c)
{
	t_inp	*tmp;

	tmp = (*inp)->next;
	(*inp)->next = new_inp(c);
	(*inp)->next->previous = (*inp);
	(*inp)->next->next = tmp;
	if (tmp)
		tmp->previous = (*inp)->next;
	return ((*inp)->next);
}

void	suppr_exclaim(t_inp **inp, int i, t_sh *sh)
{
	(void)sh;
	while (--i >= 0 && (*inp)->next)
		suppr_letter(&(*inp)->next);
}

int		nothing_front_back(t_inp **input, int i)
{
	t_inp	*inp;

	inp = (*input);
	if (inp->previous)
		return (0);
	while (inp && inp->c && i--)
		inp = inp->next;
	if (!inp)
		return (-1);
	return (0);
}

void	pt_next(t_inp **input, int i)
{
	(*input) = (*input)->next;
	while (i-- > 0)
		(*input) = (*input)->next;
}
