/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:07:08 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 19:07:09 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	short i;

	i = 0;
	while (s[i])
		i++;
	while (i > 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return (&((char*)s)[i]);
	return (0);
}
