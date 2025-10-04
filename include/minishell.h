/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:59:48 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/20 05:33:57 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* =========================== ERRORS ================================ */
# define NO_F_D 		": No such file or directory\n"
# define NOT_FOUND 		": command not found\n"
# define PER_DENI 		"minishell: permission denied\n"
# define IS_DIR 		": Is a directory\n"
# define HERDOC_MAX 	"bash: maximum here-doc count exceeded\n"
# define EOL          "warning: here-document delimited by end-of-file wanted\n"

/* =========================== INCLUDES ================================ */
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

/* =========================== STRUCTS ================================ */
extern int				g_exit_status;

typedef struct s_pipe_data
{
	int					i;
	int					n_cmd;
	int					prev_fd;
	int					pipe_fd[2];
	pid_t				*pid;
}						t_pipe_data;

typedef enum e_token_type
{
	WORD,
	REDIC_INP,
	REDIC_OUT,
	HERDOC,
	PIPE,
	APPEND,
}						t_type_tokens;

typedef enum e_quotes_type
{
	UNAVAIBLE,
	SINGLE_Q,
	DOUBLE_Q,
}						t_type_quotes;

typedef struct s_token
{
	char				*value;
	t_type_tokens		token_type;
	t_type_quotes		quote_type;
	struct s_token		*next;
}						t_tokens;

typedef struct s_env
{
	char				*name;
	char				*paths;
	struct s_env		*next;
}						t_envs;

typedef struct s_redirec
{
	char				*file;
	t_type_quotes		type_quotes;
	t_type_tokens		type_tokens;
	struct s_redirec	*next;
}						t_redirection;

typedef struct s_commands
{
	char				**env;
	char				**args;
	t_type_quotes		*_type_quotes;
	int					append;
	int					herdoc;
	int					detect_signal;
	char				*her_file;
	t_redirection		*redirection;
	struct s_commands	*next;
}						t_commands;

/* =========================== LOGO ============================ */
void					ft_mouad_o_mouaad(void);

/* ================================= PARSING ===================*/
void					update_variable(int *position, int *findex,
							int number_her);
int						ft_redirect_in_out(t_commands *command, int type);
char					*get_home(char **env);
char					**create_copy_env(char **env, int option);
int						is_only_space(char *str);
char					*ft_strrchr(const char *str, int chr);
t_type_tokens			get_token_type(char *value);
int						terminal_process(char **env);
void					link_the_token(t_tokens **tokens, char *value,
							t_type_tokens token, t_type_quotes *quote);
void					ft_lstadd_env(t_envs **envire, char *name, char *paths);
void					check_input(char *_input, char ***env);
void					expand_level_tokens(t_envs *envi, t_tokens *tokens);
t_commands				*pars_and_get_commands(t_tokens *tokens);
int						check_commands_order(t_tokens *tokens);
char					**ft_realloc(char **tab, char *new_str);
char					*case_of_exit_status(char *value, int *i);
char					*get_the_normal_word(char *word, int *j,
							char *last_value);
char					*get_the_normal_word_s(char *word, int *j,
							char *last_value);
char					*get_the_variable_value(t_envs *envs, char *str);
char					*add_chr_chr(char *value, char c, int *j);
char					*check_the_envir(char *str, int *i, t_envs *en,
							char *last_value);
t_tokens				*get_redirectiont_tokens(char *_input);
void					handle_signals(void);
void					handle_child_signals(void);
int						check_the_herdoc(t_commands *commands, t_envs *envire);
char					*case_of_the_v_digit(char *value, int *i,
							char *last_value);
void					action_signal(int sig);
int						len_args(char **args);
void					export_variable(char **args, char ***env);
void					new_promot(int sig);
int						ft_strcmp(char *s1, char *s2);
int						check_variable_exist(char *v, char **env);
int						get_the_index_v(char **env, char *name);
void					*my_malloc(size_t size, int mode); // free all
char					*case_of_2q(char *value, t_envs *envs, int *i,
							char *last_value);
void					read_from_the_herdoc(t_redirection *reds, t_envs *envs,
							char *name);
char					*file_creator(void);
int						ft_count_her(t_redirection *red);
int						set_the_value_env(char **env, char *key, char *path,
							int index);
void					add_to_env(char *variable, char ***env);

/* =========================== BUILT-INS ================================ */
int						b_echo(char **args);
int						b_cd(char **args, char **env);
int						b_pwd(char **env);
int						b_unset(char **args, char **env);
int						b_exit(char **args, int *l_command_exit);
int						b_export(char **args, char ***env);
int						b_env(char **env);

/* =============================== EXECUTION =========================== */
void					execution_start(t_commands *commands, char ***envs);
int						ft_how_many_commands(t_commands *commands);
int						ft_builtin_checker(char *cmd);
void					ft_builtin_command_handler(t_commands *command,
							char ***env);
int						ft_redirections_handler(t_commands *command, int type);
int						ft_herdoc_executor(char *herdocfile);
int						ft_redirect_input_executor(t_commands *cmd, int type);
int						ft_append_executor(t_commands *cmd, int type);
int						ft_redirect_output_executor(t_commands *cmd, int type);
void					ft_many_commands_handler(int len, t_commands *commands,
							char ***env);
int						ft_dot_and_double_dots_handler(char *cmd);
void					ft_builtin_command_executor(t_commands *command,
							char ***env, int *exit_status);
int						ft_external_command_handler(t_commands *command,
							char **env);
void					child_signals_handler(void);
void					ft_one_command_handler(t_commands *commands,
							char ***envs);
void					ft_external_command_executor(t_commands *command,
							char **env);
int						check_if_dir(char *dir);
char					*get_the_cmd_path_3(char **env);
char					*get_the_cmd_path_2(char *cmd, char **env);
char					*get_the_cmd_path_1(char *cmd, char **env);
void					close_unused_fds(t_pipe_data *d);
void					ft_exact_path_error(t_commands *commands);
int						ft_execve(char *exact_path, t_commands *commands,
							char **env);
void					ft_exit(int status);
void					set_signals_parent(void);
void					init_pipe_data(int len, t_pipe_data *d,
							t_commands *commands);
int						handle_pipe_error(t_pipe_data *d);
void					handle_parent_process(t_pipe_data *d,
							t_commands *commands);
void					handle_child_process(t_commands *commands,
							t_pipe_data *d, char ***env);
int						handle_embiguous(t_commands *cmd, int builting);
void					execute_piped_loop(t_commands *commands, t_pipe_data *d,
							char ***env);
void					wait_for_all(pid_t *pid, int n);

#endif
