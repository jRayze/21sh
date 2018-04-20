/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:12:00 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:12:00 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"
#include "builtin.h"

int			export_it(t_sh *sh, char *key, char *name)
{
	char	*tab[3];

	tab[0] = "export";
	tab[2] = NULL;
	tab[1] = key;
	builtin_setenv(tab, sh);
	tab[1] = name;
	return (builtin_unset(tab, sh));
}

int			builtin_export(char **exec, t_sh *sh)
{
	t_loc	*cp;
	int		i;

	cp = sh->loc;
	i = 0;
	if (!exec[1])
		return (builtin_local(exec, sh));
	if (cp == NULL || too_big(exec))
		return (0);
	while (exec[++i])
	{
		while (cp)
		{
			if (matching_name(cp->content, exec[i]))
			{
				export_it(sh, cp->content, exec[i]);
				break ;
			}
			cp = cp->next;
		}
		cp = sh->loc;
	}
	return (0);
}
