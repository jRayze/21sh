#include "minishell.h"

t_

void    print_match(t_readdir *list)
{
    while (list->next)
    {
        if (list->match == 1)
            ft_putendl(list->file);
        list = list->next;
    }
}
int    str_is(char *args, t_readdir *list)
{
    int i;

    i = 0;
    while (list->next)
    {
        if (!strcmp(args, list->file))
        {    
            list->match = 1;
            i = 1;
        }
        list = list->next;
    }
    return (i);
}

void    get_star(char *args, t_readdir *list)
{
    if (char_in_str(args, '*'))
        get_match(args, list);
    else
        str_is(args,list)
    print_match(list);
}