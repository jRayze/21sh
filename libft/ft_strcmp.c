/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:03:10 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 19:03:12 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = ((unsigned char*)s1);
	s22 = ((unsigned char*)s2);
	while (s11[i] == s22[i] && s11[i] != '\0' && s22[i] != '\0')
	{
		i++;
	}
	return (s11[i] - s22[i]);
}
