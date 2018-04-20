/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:04:46 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 19:04:47 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	lenght;
	int		i;

	i = 0;
	if (!s2 || !s1)
		return (NULL);
	lenght = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str = (char*)malloc(sizeof(char) * lenght)))
		return (NULL);
	lenght = -1;
	while (++lenght < ft_strlen(s1))
	{
		str[i] = s1[lenght];
		i++;
	}
	lenght = 0;
	while (lenght < ft_strlen(s2))
	{
		str[i] = s2[lenght];
		lenght++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
