/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:08:20 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:08:22 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "../libft/includes/libft.h"

typedef struct			s_pipe
{
	int					cote[2];
}						t_pipe;

typedef struct			s_redir
{
	int					redir[3];
	char				*file;
	char				**heredoc;
	struct s_redir		*next;
}						t_redir;

typedef struct			s_list_c
{
	int					sep_type;
	char				**cont;
	void				*func;
	int					nb_arg;
	int					nb_here;
	t_redir				*redirs;
	int					status;
	struct s_list_c		*prev;
	struct s_list_c		*next;
}						t_listc;

typedef struct			s_close
{
	int					flag;
	struct s_close		*next;
	struct s_close		*previous;
}						t_close;

typedef struct			s_bin
{
	char				*name;
	struct s_bin		*next;
}						t_bin;

typedef struct			s_env
{
	char				*env;
	struct s_env		*next;
}						t_env;

typedef struct			s_loc
{
	char				*content;
	struct s_loc		*next;
}						t_loc;

typedef struct			s_var
{
	char				*var;
	struct s_var		*next;
}						t_var;

typedef struct			s_inp
{
	char				c;
	int					pos;
	struct s_inp		*next;
	struct s_inp		*previous;
}						t_inp;

typedef struct			s_inpl
{
	int					type;
	struct s_inp		*inp;
	struct s_inpl		*next;
	struct s_inpl		*previous;
}						t_inpl;

typedef struct			s_his
{
	struct s_inp		*inp;
	struct s_his		*next;
	struct s_his		*previous;
}						t_his;

typedef struct			s_sh
{
	char				*tty;
	int					tty_fd;
	int					ctrl_c;
	char				*home_env;
	char				*clipboard;
	char				*comp_debug;
	char				*comp_remain;
	char				*comp_path;
	char				*save_path;
	int					comp_builtin;
	int					old_len;
	int					over;
	int					dec;
	char				buff[6];
	char				expected_quote;
	int					context;
	int					command_lenght;
	int					fd;
	int					i;
	int					aggr_fail;
	int					err;
	pid_t				pid;
	int					posy;
	int					diff;
	int					prompt_len;
	int					pos_at;
	int					inp_len;
	int					history_len;
	struct s_his		*history_pos;
	int					hist_res;
	int					width;
	int					retval;
	int					search;
	int					failed_search;
	char				pwd[2048];
	char				*man_path;
	unsigned int		hash_size;
	struct s_bin		*bin;
	struct s_env		*env;
	struct s_loc		*loc;
	struct s_inpl		*inpl;
	struct s_his		*history;
	struct s_his		*search_pos;
	struct s_inp		*his_search;
	struct s_close		*close;
	struct s_hash		**hash;
}						t_sh;

#endif
