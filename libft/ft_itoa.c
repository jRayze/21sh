/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:56:23 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 18:56:25 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static	char	*fillstr(char *str, short lenght, long n, short isneg)
{
	if (isneg)
		str[0] = '-';
	str[lenght] = '\0';
	while (n > 9)
	{
		str[lenght - 1] = n % 10 + 48;
		n /= 10;
		lenght--;
	}
	str[lenght - 1] = n % 10 + 48;
	return (str);
}

char			*ft_itoa(int n)
{
	short	len;
	short	isneg;
	char	*str;
	long	tmp;

	len = 1;
	isneg = n < 0;
	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (tmp /= 10)
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	str = fillstr(str, len, n, isneg);
	return (str);
}
