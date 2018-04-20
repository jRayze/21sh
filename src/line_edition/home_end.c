/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:32:22 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:32:23 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void		home_end_shortcut(t_sh *sh, int len, int active)
{
	if (active == 1)
	{
		while (len > sh->width)
		{
			len -= sh->width;
			ft_putstr(tgetstr("do", NULL));
		}
		while (len--)
			custom_right(sh);
	}
	else
	{
		while (len > sh->width)
		{
			len -= sh->width;
			ft_putstr(tgetstr("up", NULL));
		}
		while (len--)
			custom_left(sh);
	}
}

void		home(t_sh *sh, t_inp *cp)
{
	int		len;

	len = 0;
	if (cp->pos != 2)
		custom_left(sh);
	cp->pos = 0;
	while (cp->previous && (len++ > -1))
		cp = cp->previous;
	home_end_shortcut(sh, len, 0);
	cp->pos = 2;
}

void		end(t_sh *sh, t_inp *cp)
{
	int		len;

	len = 0;
	if (cp->pos == 2)
		custom_right(sh);
	cp->pos = 0;
	while (cp->next && (len++ > -1))
		cp = cp->next;
	home_end_shortcut(sh, len, 1);
	cp->pos = 1;
}

void		home_end(t_sh *sh, t_inp **inp, int active)
{
	t_inp	*cp;

	if ((cp = get_to_pos(inp)))
	{
		if (active == 1)
			end(sh, cp);
		else
			home(sh, cp);
	}
}
