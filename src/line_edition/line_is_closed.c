/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_closed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:33:07 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:33:07 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	check_context_quote(t_sh *sh)
{
	if (!sh->close)
		s_close_add(QUOTE, &sh->close);
	else if (sh->close->flag == QUOTE)
		delete_last_close(&sh->close);
}

void	check_context_dquote(t_sh *sh)
{
	if (!sh->close)
		s_close_add(DQUOTE, &sh->close);
	else if (sh->close->flag == DQUOTE)
		delete_last_close(&sh->close);
}

int		check_context_backslash(t_sh *sh)
{
	if (sh->close && sh->close->flag & QUOTE)
		return (0);
	return (1);
}

int		line_is_closed(t_sh *sh, t_inp **inp)
{
	t_inp	*cp;

	if ((cp = (*inp)))
	{
		while (cp)
		{
			if (cp->c == '\'')
				check_context_quote(sh);
			if (cp->c == '\"')
				check_context_dquote(sh);
			if (cp->c == '\\' && check_context_backslash(sh))
			{
				if (cp->next)
					cp = cp->next;
				else
					return (print_expected_prompt(sh, &sh->close));
			}
			cp = cp->next;
		}
	}
	if (sh->close)
		return (print_expected_prompt(sh, &sh->close));
	return (1);
}
