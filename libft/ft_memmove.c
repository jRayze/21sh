/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:59:39 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 18:59:43 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst > src)
		while (len--)
			((char*)dst)[len] = ((char*)src)[len];
	else
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	return ((char*)dst);
}
