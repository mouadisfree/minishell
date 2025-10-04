/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex07_external_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 02:04:10 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/19 22:17:35 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_external_command_executor(t_commands *command, char **env)
{
	char	*path;

	path = NULL;
	if (command->args)
		path = get_the_cmd_path_1(command->args[0], env);
	if (!path || !path[0])
		ft_exit(0);
	if (!path || !ft_strcmp(path, NOT_FOUND) || !ft_strcmp(path, PER_DENI)
		|| !ft_strcmp(path, IS_DIR) || !ft_strcmp(path, NO_F_D))
		ft_exit(g_exit_status);
	execve(path, command->args, env);
	perror("");
	exit(127);
}

int	ft_external_command_handler(t_commands *command, char **env)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid < 0)
		return (perror("fork :\n"), 1);
	if (pid == 0)
	{
		child_signals_handler();
		if (ft_redirections_handler(command, false) != -1)
			ft_external_command_executor(command, env);
		else
			ft_exit(1);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_exit_status = 128 + WTERMSIG(status);
	if (g_exit_status == 130)
		printf("\n");
	if (g_exit_status == 131)
		printf("Quit : core dumped\n");
	return (0);
}
