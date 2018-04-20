/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:58:28 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 18:58:29 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void *ret;

	if (!(ret = (void *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
