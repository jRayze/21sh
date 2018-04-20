/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:58:54 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 18:58:57 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	v;
	unsigned char	*str;
	size_t			i;

	v = (unsigned char)c;
	str = (unsigned char*)s;
	i = 0;
	while (i < n && str[i] != v)
		i++;
	if (i < n && str[i] == v)
		return (&str[i]);
	return (NULL);
}
