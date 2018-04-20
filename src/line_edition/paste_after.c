/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_after.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:33:53 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:33:54 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

char		*get_clipboard_before(t_inp *inp, int *dec, t_sh *sh)
{
	char	*ret;
	int		cp;

	(*dec) = 0;
	cp = 0;
	while (inp)
	{
		(*dec)++;
		cp++;
		if (inp->previous)
			inp = inp->previous;
		else
			break ;
	}
	restore_cursor_pos(cp, sh);
	if (!(ret = (char*)malloc(sizeof(char) * (*dec) + 1)))
		return (NULL);
	ret[(*dec)] = '\0';
	cp = -1;
	while (++cp < (*dec))
	{
		ret[cp] = inp->c;
		inp = inp->next;
	}
	return (ret);
}

void		free_list_before(t_inp **cp)
{
	t_inp	*cpp;
	t_inp	*tmp;

	if ((cpp = (*cp)))
	{
		while (cpp)
		{
			tmp = cpp;
			cpp = cpp->previous;
			free(tmp);
		}
	}
}

void		update_cut_before(int dec, t_inp **inp, t_sh *sh)
{
	t_inp	*cp;
	int		decp;
	int		remaining;

	remaining = 0;
	if ((cp = get_to_pos(inp)))
	{
		while (cp)
		{
			remaining++;
			ft_putchar(cp->c);
			check_endline(sh);
			cp = cp->next;
		}
	}
	decp = dec;
	print_spaces(dec, sh);
	decp += remaining;
	restore_cursor_pos(decp, sh);
}

void		cut_before(t_sh *sh, t_inp **inp)
{
	t_inp	*cp;
	int		dec;

	if ((cp = get_to_pos(inp)) && cp->pos == 1)
	{
		sh->ctrl_c = 0;
		if (sh->clipboard)
			free(sh->clipboard);
		sh->clipboard = get_clipboard_before(cp, &dec, sh);
		if (cp->next)
		{
			cp = cp->next;
			free_list_before(&cp->previous);
			cp->previous = NULL;
			cp->pos = 2;
			(*inp) = cp;
		}
		else
		{
			free_list_before(&cp);
			(*inp) = NULL;
		}
		update_cut_before(dec, inp, sh);
		sh->ctrl_c = 1;
	}
}

void		paste_after(t_sh *sh, t_inp **inp)
{
	int		i;
	t_inp	*cp;

	i = -1;
	sh->ctrl_c = 0;
	if (sh->clipboard[++i])
		inp_insert_posat(&sh->inpl->inp, sh->clipboard[i]);
	if ((cp = get_to_pos(inp)))
	{
		while (sh->clipboard[++i])
		{
			inp_insert_posat(&cp, sh->clipboard[i]);
			cp = cp->next;
		}
	}
	print_str(sh->clipboard, sh);
	if (i > 0)
		overwrite_remaining(sh, inp);
	sh->ctrl_c = 1;
}
