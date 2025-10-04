/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex13_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:49:00 by mokatfi@std       #+#    #+#             */
/*   Updated: 2025/08/19 22:35:54 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	close_unused_fds(t_pipe_data *d)
{
	if (d->prev_fd != -1)
		close(d->prev_fd);
	if (d->pipe_fd[0] != -1)
		close(d->pipe_fd[0]);
	if (d->pipe_fd[1] != -1)
		close(d->pipe_fd[1]);
}

void	ft_exit(int status)
{
	create_copy_env(NULL, 0);
	my_malloc(0, 0);
	close(1);
	close(0);
	close(2);
	exit(status);
}

int	ft_execve(char *exact_path, t_commands *commands, char **env)
{
	execve(exact_path, commands->args, env);
	perror("");
	exit(127);
	return (0);
}

void	ft_exact_path_error(t_commands *commands)
{
	write(2, commands->args[0], ft_strlen(commands->args[0]));
	write(2, ": command not found\n", 21);
	ft_exit(127);
}
