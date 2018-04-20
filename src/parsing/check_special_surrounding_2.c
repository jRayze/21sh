/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_surrounding_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:24:02 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:24:03 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int			check_file_redir(t_inpl *inpl)
{
	if (inpl->previous && inpl->next)
	{
		if (inpl->next->type & _FILE)
		{
			if (inpl->previous->type > 64 && inpl->previous->type < 2048)
			{
				if (!inpl->next->next)
					return (0);
				if (inpl->next->next && inpl->next->next->type != 128)
					return (0);
			}
		}
		else if (inpl->type & AGGRFILE)
			if (inpl->next && inpl->next->type & ARGUMENT)
				return (0);
	}
	return (1);
}
