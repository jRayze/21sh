/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:31:05 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:31:05 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int			escape_char(char c)
{
	if (c == ' ')
		return (1);
	if (c == '!' || c == '?')
		return (1);
	if (c == '$')
		return (1);
	if (c == '^' || c == '=')
		return (1);
	if (c == '&' || c == '\\')
		return (1);
	if (c == '*' || c == ';')
		return (1);
	if (c == '(' || c == ')' || c == '{' || c == '}')
		return (1);
	if (c == '\'' || c == '\"' || c == '`')
		return (1);
	if (c == '[' || c == ']')
		return (1);
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

int			left_word_len(int *slash, t_inp **cp)
{
	int		i;

	i = 1;
	while ((*cp)->previous)
	{
		if (is_space((*cp)->previous->c) && !escaped(&(*cp)->previous, 0))
			break ;
		if ((*cp)->previous->c == '/')
		{
			(*slash)++;
			break ;
		}
		i++;
		(*cp) = (*cp)->previous;
	}
	return (i);
}

char		*get_left_word(t_inp *cp, t_sh *sh)
{
	char	*ret;
	int		i;
	int		slash;

	slash = 0;
	free_comp(6, sh);
	if ((i = left_word_len(&slash, &cp)) == -1)
		return (NULL);
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (slash)
		sh->comp_path = get_comp_path(sh, cp);
	else
		sh->comp_path = ft_strdup("./");
	ret[i] = '\0';
	i = 0;
	while (cp && !is_space(cp->c))
	{
		ret[i++] = cp->c;
		cp = cp->next;
	}
	return (ret);
}

void		erase_completion(t_sh *sh, t_inp **inp)
{
	t_inp	*cp;
	int		dec;

	if (!sh->comp_remain)
		return ;
	dec = 0;
	if ((cp = get_to_pos(inp)))
	{
		while (cp)
		{
			dec++;
			cp = cp->next;
		}
	}
	dec += ft_strlen(sh->comp_remain) + 1;
	free_comp(1, sh);
	print_spaces(dec, sh);
	while (dec--)
		custom_left(sh);
	overwrite_remaining(sh, inp);
}

void		autocompletion(t_inp **inp, t_sh *sh)
{
	t_inp	*cp;

	if ((cp = get_to_pos(inp)) && cp->pos != 2)
	{
		if (!cp->next || is_space(cp->next->c))
		{
			if (!is_space(cp->c))
			{
				if (cp->c != '/')
				{
					if ((sh->comp_debug = get_left_word(cp, sh)))
						print_completion(sh, &sh->inpl->inp);
				}
				else
					free_comp(11, sh);
			}
			else
				free_comp(11, sh);
		}
		else
			free_comp(3, sh);
	}
	else if (sh->comp_remain)
		rewrite_beginning(sh, cp);
}
