/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:31:44 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:31:45 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void		custom_return(void)
{
	ft_putstr(tgetstr("do", NULL));
	ft_putstr(tgetstr("cr", NULL));
}

int			inpl_add_new(t_inpl **inpl, int print)
{
	t_inpl	*new;

	if (!(new = (t_inpl*)malloc(sizeof(t_inpl))))
		return (print);
	new->inp = NULL;
	new->next = NULL;
	new->previous = (*inpl);
	(*inpl)->next = new;
	(*inpl) = (*inpl)->next;
	return (print);
}

void		process_line(t_sh *sh)
{
	while (sh->inpl && sh->inpl->previous)
		sh->inpl = sh->inpl->previous;
	sh->ctrl_c = 1;
	parse(sh);
	while (sh->history && sh->history->previous)
		sh->history = sh->history->previous;
	print_prompt(sh);
}

void		enter_key(t_sh *sh)
{
	int		print;

	print = 1;
	custom_return();
	if (!sh->close)
	{
		if (!line_is_closed(sh, &sh->inpl->inp))
			print = inpl_add_new(&sh->inpl, 0);
	}
	else
	{
		if (line_is_closed(sh, &sh->inpl->inp))
			print = 1;
		else
			print = inpl_add_new(&sh->inpl, 0);
	}
	if (print)
		process_line(sh);
}
