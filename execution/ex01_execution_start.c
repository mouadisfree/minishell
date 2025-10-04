/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01_execution_start.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 02:30:55 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/21 06:39:57 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execution_start(t_commands *commands, char ***envs)
{
	int	commands_n;

	if (!commands->args && !commands->redirection)
		return ;
	commands_n = 0;
	commands_n = ft_how_many_commands(commands);
	if (commands_n == 1)
		ft_one_command_handler(commands, envs);
	else
		ft_many_commands_handler(commands_n, commands, envs);
}
