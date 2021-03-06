/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:08:15 by jamerlin          #+#    #+#             */
/*   Updated: 2018/04/19 15:55:01 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define TERM "xterm-256color"
# define DEBUG			0
# define TTY_MAX		10000

# define DQUOTE			1
# define QUOTE			2

# define IN				0
# define OUT			1
# define AOUT			3
# define HEREDOC		4
# define ERR_OUT		2
# define READ_END		0
# define WRITE_END		1

# define HERE			1
# define PIPE			2
# define AND			4
# define OR				8
# define TOFILE			16
# define ATOFILE		32
# define TOEXE			64
# define ARGUMENT		128
# define COMMAND		256
# define BUILTIN		512
# define _FILE			1024
# define SEMICOLON		2048
# define AGGR			4096
# define AGGRFILE		8192
# define AGGROUT		16384
# define LAGGR			32768
# define LAGGRIN		65536
# define CLOSEAGGR		131072

# include <termcap.h>
# include <termios.h>
# include <curses.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/syslimits.h>
# include <sys/ioctl.h>

# include "typedef.h"
# include "hash.h"

void					print_splitted(t_inpl **inpl);
void					print_converted(t_inp **inp, int type);

struct termios			g_old_term;
struct termios			g_new_term;
struct s_sh				*g_sh;

int						init_term(void);
void					try_exit(t_sh *sh, t_inp **inp);
void					init_variables(t_sh *sh);
void					get_bin(t_env **env, t_sh *sh);
t_bin					*new_bin(char *name);
void					add_builtin_completion(t_sh *sh);
void					bin_push_front(t_bin **bin, char *name);
void					signal_init(void);
void					signal_exec(void);
void					signal_event(int signo);
void					suicide_squad(int signo);

char					**env_list_to_char(t_env **env);
char					*get_specific_env(char *env, t_env **envlist);
char					*get_specific_loc(char *env, t_loc **envlist);
void					get_env(char **env, t_sh *sh);
void					env_push_back(t_env **envlist, char *env);
t_env					*new_env(char *env);
void					free_char_array(char **array);

void					print_prompt(t_sh *sh);
void					tild_prompt(t_sh *sh);
void					prompt_colors(int i);

void					free_null(char **str);

void					erase_inp_spaces(t_sh *sh, t_inp **inp);
void					ft_putstr_endline(char *str, t_sh *sh);
void					check_pasted(t_sh *sh);
void					treat_input(t_sh *sh);
void					classic_edition(t_inp **inp, t_sh *sh, int flag);
void					add_delete_letter(t_sh *sh);
void					delete_letter(t_sh *sh, t_inp **inp);
void					delete_first_letter(t_inp *cp, t_inp **inp);
void					delete_in_between(t_inp *cp);
void					delete_beginning(t_inp **inp, t_inp *cp);
void					delete_after(t_sh *sh, t_inp **inp);
void					overwrite_remaining(t_sh *sh, t_inp **inp);
void					overwrite_deleted(t_sh *sh, t_inp **inp);
int						check_dimentions(t_sh *sh);
void					check_endline(t_sh *sh);
int						print_inp(t_inp *cp, t_sh *sh);
void					inp_insert_chain(t_inp **src, t_sh *sh);
void					print_str(char *str, t_sh *sh);
void					restore_cursor_pos(int nb, t_sh *sh);
void					restore_cursor_right(int nb, t_sh *sh);
void					print_t_inp(t_inp **inp);

t_inpl					*new_inpl(t_inp **inp, int type);
void					inpl_push_back(t_inpl **inpl, t_inp **inp, int type);
void					free_inpl(t_inpl **inpl);

void					move_cursor(t_sh *sh, t_inp **inp, char c);
void					move_left(t_sh *sh, t_inp **inp);
void					move_right(t_sh *sh, t_inp **inp);
int						custom_left(t_sh *sh);
int						custom_right(t_sh *sh);

int						is_space(char c);
void					jump_words(t_sh *sh, char c);
void					jump_left(t_sh *sh, t_inp **inp);
void					jump_right(t_sh *sh, t_inp **inp);
void					home_end(t_sh *sh, t_inp **inp, int active);
void					end(t_sh *sh, t_inp *cp);
void					home(t_sh *sh, t_inp *cp);

void					jump_up(t_sh *sh, t_inp **inp);
void					jump_down(t_sh *sh, t_inp **inp);

t_inp					*new_inp(char c);
t_inp					*inp_dup(t_inp **inp);
void					inp_insert_posat(t_inp **inp, char c);
void					inp_insert_posat_remake(t_inp **inp, char c);
void					insert_middle(t_inp *first, t_inp *tmp);
void					insert_first(t_inp *first, t_inp *tmp, t_inp **inp);
void					insert_beginning(t_inp *first, t_inp *tmp);

t_inp					*get_to_pos(t_inp **inp);
int						pos_at(t_inp **inp, int len);
int						inp_list_len(t_inp **inp);

void					check_shortcut(t_sh *sh);
void					clear_screen(t_sh *sh);
void					enter_key(t_sh *sh);
void					cut_after(t_sh *sh, t_inp **inp);
void					cut_before(t_sh *sh, t_inp **inp);
char					*get_clipboard(t_inp *inp, int *dec, t_sh *sh);
char					*get_clipboard_before(t_inp *inp, int *dec, t_sh *sh);
void					free_list_from_here(t_inp *cp);
void					free_list_from_beginning(t_inp **inp);
void					free_list_before(t_inp **cp);

void					paste_after(t_sh *sh, t_inp **inp);

int						inp_to_inp_cmp(t_inp **inp1, t_inp **inp2);
void					history_push_front(t_his **his, t_inp *inp, t_sh *sh);
t_his					*history_new(t_inp *inp, t_sh *sh);
t_inp					*inp_insert_chain_his(t_inp **src, t_sh *sh, int nb);
int						history_len(t_his **history);

t_his					*new_his(char *str);
void					str_to_inp(char *str, t_inp **inp);

void					search_history_backward(t_sh *sh, t_his **history);
void					search_history_forward(t_sh *sh, t_his **history);
void					search_history_inp(t_sh *sh, t_inp **inp);
void					clear_line(t_sh *sh, t_inp **inp);

char					*inp_to_char(t_inp **inp, t_sh *sh);
void					restore_history_from_file(t_sh *sh);
int						check_empty_line(t_inp **inp);

void					autocompletion(t_inp **inp, t_sh *sh);
void					print_completion(t_sh *sh, t_inp **inp);
int						preview_autocompletion(t_sh *sh, t_inp *cp, int which);
void					not_found(t_sh *sh, t_inp *inp);
int						get_diff(char *fl, t_sh *sh);
void					print_completion_builtin(t_sh *s, t_inp *i, t_bin **b);
void					delete_remain(t_sh *sh, char *remain);
int						complete_builtin(t_inp **inp);
int						escape_char(char c);
void					found(t_sh *sh, DIR *od, struct dirent *fl, t_inp *cp);
void					insert_completion(t_sh *sh, t_inp **inp);
void					erase_completion(t_sh *sh, t_inp **inp);
char					*get_left_word(t_inp *cp, t_sh *sh);
int						left_word_len(int *slash, t_inp **cp);
char					*get_comp_path(t_sh *sh, t_inp *cp);
void					overwrite_remaining_comp(t_sh *sh, t_inp **inp, int i);
void					free_comp(int i, t_sh *sh);
void					print_spaces(int nb, t_sh *sh);
void					rewrite_beginning(t_sh *sh, t_inp *cp);
void					completion_readdir(DIR *od, t_sh *sh, t_inp *cp);
int						literal_path(t_sh *sh);

int						line_is_closed(t_sh *sh, t_inp **inp);
int						print_expected_prompt(t_sh *sh, t_close **close);
void					s_close_add(int flag, t_close **close);
void					delete_last_close(t_close **close);
t_close					*new_close(int flag);
int						inpl_add_new(t_inpl **inpl, int print);
void					process_line(t_sh *sh);
void					custom_return(void);

int						ending_char(char c);
int						inp_cmp(t_inp **inp, char *str);
void					try_insert_variable(t_inp **inp, t_sh *sh);
void					try_insert_home(t_inp **inp, t_sh *sh);
void					split_line(t_inpl **inpl, t_inp **clean, t_sh *sh);
int						escaped(t_inp **inp, int context);
int						special_tok(char c);
int						ending_special_char(char c);
int						redir(t_inp *inp);
int						check_quoting(t_inp **cp, int context);
int						empty_quote(int context, t_inp **inp);
int						right_context(int context);
int						check_key(char key);
int						try_update_context(char c, int flag);

void					*convert_splitted(t_inpl **inpl, t_sh *sh);
int						check_previous(int type);
void					convert_quote(t_inp **inp);
void					convert_dquote(t_inp **inp, t_sh *sh);
void					convert_bquote(t_inp **inp, t_sh *sh);

void					get_previous_inp(t_inp **inp, t_inp **previous);
void					relink_with_end(t_inp **inp);
void					rep_backslash(char c, t_inp **i, t_inp **u);

void					parse_backquotes(t_inp **inp, t_sh *sh);

void					*special_error(t_inp **inp);
int						check_fd_aggr_right(t_inp *cp);
int						check_fd_aggr_left(t_inp *cp);
int						check_right_arrow(t_inp **inp);
int						check_left_arrow(t_inp **inp);
int						check_pipe_or(t_inp **inp);
int						check_and(t_inp **inp);
int						check_semicolon(t_inp **inp);
int						check_out_aggr(t_inp *inp);
int						check_mult_aggr(t_inp **inp);
int						check_left_aggr(t_inp *inp);

int						not_closed(t_inpl *cp);
char					*inp_to_cont(t_inp **inp);

int						get_tty(t_sh *sh, char *av);
char					*custom_strcat(char *s1, char *s2);
int						special_char(char c);
void					custom_itoa(int *pos, char *buff, int nb);
void					tty_debug(t_sh *sh, t_inp **inp);
void					opti_strcat(int *pos, char *buff, char *buff2, int es);
int						get_len(int nb);

void					parse(t_sh *sh);
t_inp					*concat_inpl(t_inpl **inpl, t_sh *sh);
void					contcat_inp(t_inp **inp, t_inp **ret);
int						empty_inp(t_inp **inp, t_sh *sh);

void					lexer_parser(t_inp **inp, t_sh *sh);
int						working_context(int context, char c);
int						update_context(int context, int flag);
void					dquote_inp(t_inp **cp, t_sh *sh);
void					quote_inp(t_inp **cp, t_sh *sh);
void					bquote_inp(t_inp **cp, t_sh *sh);

int						redirection(t_inp **inp);

int						check_special_surrounding(t_inpl **inpl);
int						check_file_redir(t_inpl *inpl);
t_redir					*return_last_redir(t_redir **redir);

void					print_variable(t_inp **cp, t_sh *sh);
int						valid_variable_char(char c);
char					*parse_variable_name(t_inp **inp);

void					print_heredoc(char *ending, t_sh *sh);
int						treat_input_here(t_sh *sh, t_inpl **inpl, char *end);
int						check_pasted_here(t_sh *sh, t_inpl **inpl, char *end);
char					**allocate_cont(t_inpl **inpl);
char					*allocate_eof(t_inp **inp);
t_inpl					*allocate_here_cont(void);
char					**get_heredoc(t_inp **inp);
int						tokenize_splitted(t_inpl **i, t_sh *sh, t_listc **t);
char					**concat_content(t_inpl **inpl);
t_listc					*new_token(void);
int						keep_going(int type);
int						is_redirection(int type);
void					tok_push_back(t_listc **tok, t_listc *add);
char					*get_file_name(t_inp **inp);
void					free_tokens(t_listc **tok);

char					*add_file_redir(int redir[3], t_inp **file, int type);
char					**add_here_redir(int redir[3], t_inp **eof);
char					*add_aggr_redir(int redir[3], t_inpl **inpl, int type);
void					add_laggr_redir(int redir[3], t_inpl **inpl, int type);
void					redir_debug(char *file, int redir[3]);

int						fork_command(char *path, char **exec, char **tab);

void					signal_handler(int inp);
void					signal_newline(int inp);
void					execute_tokens(t_listc **tok, t_sh *sh);
void					exec_cli(char *cli, t_listc *tok, t_sh *sh);
int						condition_is_valid(t_sh *sh, t_listc *cmd);

void					prepare_pipe(t_listc *cmd);
void					count_heredoc(t_listc *red);
void					ft_cmd_pipe(t_listc *cmd, t_sh *i_env);
void					closed_unused_fd(int fils, int nb_tube, t_pipe *t);
void					pipe_tmp(t_listc *cmd, int i, t_pipe *t, t_sh *i_env);
void					ft_pipe(t_listc *cmd, int *pid, t_pipe *t, t_sh *i);
int						do_pipe(t_listc *cmd, int *pid, t_pipe *t, t_sh *i);
int						init_pipe(t_listc *cmd, t_pipe *t, t_sh *i_env);

void					heredock_redirect(t_listc *cmd, t_pipe *t, int i);
void					redirect(t_listc *cmd, t_pipe *t, int i, t_redir **r);
void					reset_fd(int save_fd[3]);
void					sve_fd(int save_fd[3]);
void					do_aggre(t_listc *cmd, t_pipe *t, int i);

void					errexit(char *str);
char					*command_path(t_env **env, char *command, t_sh *sh);
void					close_tabtube(int len, t_pipe *tabtube);
void					print_access_error(char *fullpath);
void					print_err(int err, char *path);
t_pipe					*new_tabtube(int len);
void					dup_fd(t_listc *cmd, t_pipe *tabtube, int i);

void					*get_builtin_function(char *command);
int						err_msg(char *message, char *name, int ret);

int						fork_builtin(int (*c)(char **a, char **b),
						char **e, char **d);

int						change_dir(char **exec, t_env **env);
int						parse_flag(char **exec);
int						check_flag(int flag, char letter);
char					*check_path_bin(char *path, t_sh *sh);

void					history_search(t_sh *sh);
void					erase_inp(t_sh *sh, t_inp **inp);
void					erase_previous_search(t_sh *sh, t_inp **search_pos);
void					treat_input_search(t_sh *sh);
void					add_delete_letter_search(t_sh *sh);
void					search_input(t_sh *sh);
void					switch_search_mode(t_sh *sh, t_inp **his_search);
void					print_srch_frwrd(t_sh *s, t_inp **a, t_his **h, int r);
void					print_srch_bckwrd(t_sh *s, t_inp **a, t_his **h, int r);
void					print_match(t_sh *sh);
void					insert_search(t_sh *sh, t_inp **h, t_inp **his_pos);
void					hide_history_search(t_sh *sh, t_inp **a, t_inp **h);
void					insert_found_history(t_sh *sh, t_inp **search_pos);
void					restaure_inp(t_sh *sh, t_inp **inp);

int						path_eval(char *path);
char					*find_man_path(char *relativ);

#endif
