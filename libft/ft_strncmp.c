/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:05:59 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 19:06:00 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = ((unsigned char*)s1);
	s22 = ((unsigned char*)s2);
	i = 0;
	while (s11[i] == s22[i] && s11[i] != '\0' && s22[i] != '\0' && n > 0)
	{
		n--;
		i++;
	}
	if (n == 0)
		return (0);
	return (s11[i] - s22[i]);
}
