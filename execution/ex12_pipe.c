/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex12_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:47:30 by mokatfi@std       #+#    #+#             */
/*   Updated: 2025/08/16 09:58:39 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	handle_fork_and_process(t_commands *commands, t_pipe_data *d, char ***env)
{
	d->pid[d->i] = fork();
	if (d->pid[d->i] == -1)
	{
		perror("fork");
		g_exit_status = 1;
		return (-1);
	}
	if (d->pid[d->i] == 0)
		handle_child_process(commands, d, env);
	else
		handle_parent_process(d, commands);
	return (0);
}

void	execute_piped_loop(t_commands *commands, t_pipe_data *d, char ***env)
{
	while (commands)
	{
		if (commands->next)
		{
			if (handle_pipe_error(d) == -1)
				return ;
		}
		if (handle_fork_and_process(commands, d, env) == -1)
			return ;
		commands = commands->next;
		d->i++;
	}
}

void	wait_for_all(pid_t *pid, int n)
{
	int	i;
	int	status;

	i = 0;
	while (i < n)
	{
		waitpid(pid[i], &status, 0);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		i++;
	}
}

void	init_pipe_data(int len, t_pipe_data *d, t_commands *commands)
{
	(void)commands;
	d->i = 0;
	d->n_cmd = len;
	d->prev_fd = -1;
	d->pid = my_malloc(d->n_cmd * sizeof(pid_t), 1);
}

int	handle_pipe_error(t_pipe_data *d)
{
	if (pipe(d->pipe_fd) == -1)
	{
		perror("pipe");
		g_exit_status = 1;
		return (-1);
	}
	return (0);
}
