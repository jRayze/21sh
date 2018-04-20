/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:14:22 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:14:23 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"
#include "builtin.h"

int		env_verbose(int verb, char *exec)
{
	if (verb > 0)
	{
		ft_putstr_fd("#env: setenv    ", STDERR_FILENO);
		ft_putendl_fd(exec, STDERR_FILENO);
	}
	return (1);
}

char	**clear_realloc(int verb, char **tab)
{
	if (verb > 0)
	{
		ft_putendl_fd("#env: clearing environ", STDERR_FILENO);
	}
	env_free(tab);
	if (!(tab = (char**)malloc(sizeof(char*) * 1)))
		return (NULL);
	tab[0] = NULL;
	return (tab);
}

char	*env_key(char *env_v)
{
	char	*key;
	size_t	i;

	i = 0;
	while (env_v[i] != '=' && env_v[i] != '\0')
		++i;
	if (!(key = malloc((i + 1) * sizeof(char))))
		return (NULL);
	key[i] = '\0';
	while (i != 0)
	{
		--i;
		key[i] = env_v[i];
	}
	return (key);
}

void	hist_verbose(int i)
{
	ft_putstr("Removed ");
	ft_putnbr(i);
	ft_putendl(" entries from the history.");
}
