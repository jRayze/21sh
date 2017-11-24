/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:08:11 by gmonein           #+#    #+#             */
/*   Updated: 2017/11/08 18:08:19 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     char_in_str(char *str, char c)
{
    while (*str)
    {
        if (*str == c)
            return (1);
        str++;
    }
    return (0);
}
 
t_readdir *add_elem(t_readdir *lstfile, char *file)
{
    t_readdir *beg;
    t_readdir *newfile;

    beg = lstfile;
    newfile = (t_readdir *)malloc(sizeof(t_readdir));
    newfile->file = ft_strdup(file);
    newfile->next = NULL;
    if (!lstfile)
        return (newfile);
    while (lstfile && lstfile->next)
        lstfile = lstfile->next;
    lstfile->next = newfile;
    lstfile->next->next = NULL;
    return (beg);
}

t_readdir *init_readdir(char *path)
{
    DIR *dp;
    struct dirent *ep;
    t_readdir *lstfile;
    t_readdir *dup;

    lstfile = (t_readdir *)malloc(sizeof(t_readdir));
    lstfile->file = NULL;
    lstfile->next = NULL;
    if (!(dp = (path && path[0] != ' ') ? opendir(path) : opendir(".")))
        return (NULL);
    while ((ep = readdir(dp)))
        lstfile = add_elem(lstfile, ep->d_name);
    dup = lstfile;
    while ((dup = dup->next))
        printf("1 - %s\n", dup->file);
    return (lstfile);
}

int     auto_completion(char *line)
{
    t_readdir *curr;
    int i;

    i = 0;
    while (line[i] && line[i] != ' ' && line[i] != '\t')
        i++;
    curr = init_readdir(&line[i]);
    return (0);
   /* if (char_in_str(line, '\t'))
    {

    }*/
}