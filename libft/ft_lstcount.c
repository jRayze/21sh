/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:57:03 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 18:57:05 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_lstcount(t_list **alst)
{
	int		i;
	t_list	*chain;

	i = 1;
	chain = *alst;
	if (!chain)
		return (0);
	while (chain->next)
	{
		i++;
		chain = chain->next;
	}
	return (i);
}
