/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex14_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:49:31 by mokatfi@std       #+#    #+#             */
/*   Updated: 2025/08/19 21:38:58 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	execute_command_pipe(t_commands *commands, char ***env)
{
	char	*exact_path;

	if (commands->redirection && ft_redirections_handler(commands, 0) == -1)
		ft_exit(1);
	if (!commands || !commands->args || !commands->args[0])
		ft_exit(127);
	if (ft_strlen(commands->args[0]) == 0)
	{
		printf("command not found\n");
		ft_exit(127);
	}
	if (ft_builtin_checker(commands->args[0]))
	{
		ft_builtin_command_executor(commands, env, &g_exit_status);
		ft_exit(g_exit_status);
	}
	exact_path = get_the_cmd_path_1(commands->args[0], *env);
	if (!exact_path)
		ft_exact_path_error(commands);
	ft_execve(exact_path, commands, *env);
	return (0);
}

void	set_signals_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	input_no_output_of_pipe(t_commands *commands)
{
	int				fd_in;
	t_redirection	*tmp;

	tmp = commands->redirection;
	fd_in = -1;
	while (tmp)
	{
		if (fd_in != -1)
			close(fd_in);
		fd_in = open(tmp->file, O_RDONLY);
		if (fd_in == -1)
		{
			perror(tmp->file);
			ft_exit(1);
		}
		tmp = tmp->next;
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
}

void	handle_child_process(t_commands *commands, t_pipe_data *d, char ***env)
{
	set_signals_child();
	if (d->prev_fd != -1)
		dup2(d->prev_fd, 0);
	if (commands->next)
		dup2(d->pipe_fd[1], 1);
	close_unused_fds(d);
	execute_command_pipe(commands, env);
	ft_exit(0);
}

void	handle_parent_process(t_pipe_data *d, t_commands *commands)
{
	if (d->prev_fd != -1)
		close(d->prev_fd);
	if (commands->next)
	{
		close(d->pipe_fd[1]);
		d->prev_fd = d->pipe_fd[0];
	}
	else
	{
		close(d->pipe_fd[0]);
		close(d->pipe_fd[1]);
		d->prev_fd = -1;
	}
}
