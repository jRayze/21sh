/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:28:16 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:28:16 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int			empty_quote(int context, t_inp **inp)
{
	t_inp	*cp;

	cp = *inp;
	if (cp->c == '\'' && context & QUOTE)
		if (cp->next && cp->next->c == '\'')
			return (1);
	if (cp->c == '\"' && context & DQUOTE)
		if (cp->next && cp->next->c == '\"')
			return (1);
	if (cp->c == '\'' && !context)
		if (cp->next && cp->next->c == '\'')
			return (1);
	if (cp->c == '\"' && !context)
		if (cp->next && cp->next->c == '\"')
			return (1);
	return (0);
}

int			escaped(t_inp **inp, int context)
{
	t_inp	*cp;
	int		odd;

	odd = 2;
	if ((cp = (*inp)))
	{
		if (cp->previous && cp->previous->c == '\\')
		{
			if (cp->c == '\'' && context & QUOTE)
				return (0);
			while (cp->previous && cp->previous->c == '\\')
			{
				odd++;
				cp = cp->previous;
			}
		}
	}
	return (odd % 2);
}

void		add_token(t_inpl **inpl, t_inp **cp, t_sh *sh)
{
	t_inp	*add;

	sh->context = 0;
	add = NULL;
	while (*cp)
	{
		if (check_quoting(cp, sh->context) && !escaped(cp, sh->context))
			sh->context = try_update_context((*cp)->c, sh->context);
		if (*cp && right_context(sh->context) && ending_char((*cp)->c) &&
				!escaped(cp, sh->context))
			break ;
		if (!*cp)
			break ;
		inp_insert_posat_remake(&add, (*cp)->c);
		(*cp) = (*cp)->next;
	}
	if (add)
		inpl_push_back(inpl, &add, 0);
}

void		add_special_token(t_inpl **inpl, t_inp **cp)
{
	t_inp	*add;

	add = NULL;
	while (*cp)
	{
		if (ending_special_char((*cp)->c))
			break ;
		inp_insert_posat_remake(&add, (*cp)->c);
		(*cp) = (*cp)->next;
	}
	if (add)
		inpl_push_back(inpl, &add, 1);
}

void		split_line(t_inpl **inpl, t_inp **clean, t_sh *sh)
{
	t_inp	*cp;

	cp = *clean;
	while (cp)
	{
		while (cp && cp->c == ' ')
			cp = cp->next;
		if (!cp)
			break ;
		if (special_tok(cp->c) || redir(cp))
			add_special_token(inpl, &cp);
		else
			add_token(inpl, &cp, sh);
	}
}
