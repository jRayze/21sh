/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:16:26 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:16:26 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"
#include "builtin.h"

void	nb_verb(int *verbose)
{
	char	*str;

	(*verbose)++;
	if (*verbose > 1)
	{
		ft_putstr_fd("#env verbosity now at ", STDERR_FILENO);
		str = ft_itoa(*verbose);
		ft_putendl_fd(str, STDERR_FILENO);
		free(str);
	}
}

int		illegal_opt(char c)
{
	if (c == 'u')
		ft_putendl_fd("env: option requires an argument -- u", 2);
	else
	{
		ft_putstr_fd("env: illegal option -- ", STDERR_FILENO);
		ft_putchar_fd(c, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	return (0);
}

void	unset_verb(int verbose, char *str, char *next, char ***tab)
{
	str = (str[1]) ? &str[1] : next;
	*tab = unsetenv_tab(*tab, str);
	if (verbose > 0)
	{
		ft_putstr_fd("#env: unset    ", STDERR_FILENO);
		ft_putendl_fd(str, STDERR_FILENO);
	}
}
