/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04_builtin_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:20:00 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/20 22:11:03 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_builtin_command_executor(t_commands *command, char ***env,
		int *exit_status)
{
	int		number;
	char	*cmd;

	cmd = command->args[0];
	if (!ft_strcmp(cmd, "echo"))
		b_echo(command->args);
	if (!ft_strcmp(cmd, "cd"))
		b_cd(command->args, *env);
	if (!ft_strcmp(cmd, "env"))
		b_env(*env);
	if (!ft_strcmp(cmd, "export"))
		b_export(command->args, env);
	if (!ft_strcmp(cmd, "pwd"))
		b_pwd(*env);
	if (!ft_strcmp(cmd, "unset"))
		b_unset(command->args, *env);
	if (!ft_strcmp(cmd, "exit"))
	{
		number = b_exit(command->args, exit_status);
		g_exit_status = number;
	}
	if (!ft_strcmp(cmd, ".") || !ft_strcmp(cmd, ".."))
		ft_dot_and_double_dots_handler(cmd);
}

void	close_fds(int d_stdout, int d_stdin)
{
	dup2(d_stdout, STDOUT_FILENO);
	dup2(d_stdin, STDIN_FILENO);
	close(d_stdout);
	close(d_stdin);
}

void	printf_exit(t_redirection *red)
{
	if (!red)
		ft_putstr_fd("exit\n", 1);
	else
		ft_putstr_fd("exit\n", 2);
}

void	ft_builtin_command_handler(t_commands *command, char ***env)
{
	int (d_stdout), (d_stdin), (status);
	d_stdout = dup(STDOUT_FILENO);
	d_stdin = dup(STDIN_FILENO);
	status = ft_redirections_handler(command, true);
	if (status >= 0)
		ft_builtin_command_executor(command, env, &g_exit_status);
	if (status < 0)
		g_exit_status = 1;
	if (!ft_strcmp(command->args[0], "exit"))
	{
		printf_exit(command->redirection);
		close(d_stdout);
		close(d_stdin);
		if (g_exit_status == -1)
		{
			g_exit_status = 2;
			ft_putstr_fd("bash: exit: ", 2);
			ft_putstr_fd(command->args[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
		}
		my_malloc(0, 0);
		create_copy_env(NULL, 0);
		exit(g_exit_status);
	}
	close_fds(d_stdout, d_stdin);
}

int	ft_builtin_checker(char *cmd)
{
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") || !ft_strcmp(cmd,
			"unset") || !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "exit") || !ft_strcmp(cmd,
			"..") || !ft_strcmp(cmd, "."));
}
