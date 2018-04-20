/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:56:36 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 18:56:40 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_list_push_back(t_list **alst, void *content, size_t size)
{
	t_list *first;
	t_list *after;

	first = ft_lstnew(content, size);
	if (!*alst)
		*alst = first;
	else
	{
		after = *alst;
		while (after->next)
			after = after->next;
		after->next = first;
	}
}
