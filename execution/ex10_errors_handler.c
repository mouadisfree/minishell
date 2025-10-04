/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex10_errors_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:52:02 by mokatfi@std       #+#    #+#             */
/*   Updated: 2025/08/20 21:56:40 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	handle_embiguous(t_commands *cmd, int builting)
{
	g_exit_status = 1;
	(void)cmd;
	if (!builting)
	{
		ft_putstr_fd("minishell: ambiguous redirect: $...\n", 2);
		my_malloc(0, 0);
		exit(g_exit_status);
	}
	else
		ft_putstr_fd("minishell: ambiguous redirect: $..\n", 2);
	return (-1);
}

int	ft_dot_and_double_dots_handler(char *cmd)
{
	if (!strcmp(cmd, "."))
	{
		ft_putstr_fd("bash: .: filename argument required\n", 2);
		ft_putstr_fd(".: usage: . filename [arguments]\n", 2);
		g_exit_status = 2;
		return (1);
	}
	else if (!strcmp(cmd, ".."))
		ft_putstr_fd("..: command not found\n", 2);
	g_exit_status = 127;
	return (1);
}

int	ft_redirect_in_out(t_commands *command, int type)
{
	if (command->redirection->type_tokens == REDIC_OUT)
	{
		if (ft_redirect_output_executor(command, type) < 0)
			return (-1);
	}
	if (command->redirection->type_tokens == APPEND)
	{
		if (ft_append_executor(command, type) < 0)
			return (-1);
	}
	else
	{
		if (ft_redirect_input_executor(command, type) < 0)
			return (-1);
	}
	return (0);
}
