/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:08:55 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/11 19:08:56 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 500
# include "./includes/libft.h"

t_list	*ft_manage_fd(int fd, t_list **chain);
int		get_next_line(const int fd, char **line);
void	join(t_list **alst, char *buff, int end);

#endif
