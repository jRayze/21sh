/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:33:20 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:33:21 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char		*inp_to_cont(t_inp **inp)
{
	char	*ret;
	t_inp	*cp;
	int		len;

	ret = NULL;
	len = 0;
	if ((cp = (*inp)))
	{
		while (cp)
		{
			len++;
			cp = cp->next;
		}
		if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		ret[len] = '\0';
		len = 0;
		cp = *inp;
		while (cp)
		{
			ret[len++] = cp->c;
			cp = cp->next;
		}
	}
	return (ret);
}

char		*inp_to_char(t_inp **inp, t_sh *sh)
{
	char	*ret;
	t_inp	*cp;
	int		i;

	if (!(cp = (*inp)))
		return (NULL);
	else
	{
		if (!(ret = (char*)malloc(sizeof(char) * (sh->inp_len + 1))))
			return (NULL);
		ret[sh->inp_len] = '\0';
		i = 0;
		while (cp)
		{
			ret[i] = cp->c;
			i++;
			cp = cp->next;
		}
	}
	return (ret);
}
