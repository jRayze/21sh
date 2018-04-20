/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_updater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:24:16 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:24:34 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int			try_update_context(char c, int flag)
{
	if (c == '\'')
	{
		if (flag & QUOTE)
			return (flag - QUOTE);
		else if (!flag)
			return (flag | QUOTE);
	}
	if (c == '\"')
	{
		if (flag & DQUOTE)
			return (flag - DQUOTE);
		else if (!flag)
			return (flag | DQUOTE);
	}
	return (flag);
}

int			update_context(int context, int flag)
{
	if (context & flag)
		return (context - flag);
	return (context | flag);
}
