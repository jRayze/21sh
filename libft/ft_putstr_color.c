/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:01:59 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 19:02:02 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putstr_color(char *str, int color)
{
	write(1, "\x1B[", 2);
	write(1, ft_itoa(color), 3);
	write(1, "m", 1);
	ft_putstr(str);
	write(1, "\x1B[0m", 4);
}
