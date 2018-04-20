/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:07:36 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 19:07:37 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	short i;
	short j;

	i = 0;
	j = 0;
	if (!little[i])
		return (&((char*)big)[0]);
	while (big[i])
	{
		while (big[i] == little[j] && big[i])
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return (&((char*)big)[i - j]);
		if (j > 0)
			i = i - j;
		j = 0;
		i++;
	}
	return (0);
}
