/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:04:59 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 19:05:01 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t i;
	size_t j;

	i = ft_strlen(dst);
	j = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		if (size > i - j)
			dst[i] = '\0';
	}
	return ((size < i - j ? size : i - j) + ft_strlen(src));
}
