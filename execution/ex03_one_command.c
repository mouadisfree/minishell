/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03_one_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:15:40 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/16 17:18:01 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_one_command_handler(t_commands *commands, char ***envs)
{
	if (commands->args && ft_builtin_checker(commands->args[0]))
		ft_builtin_command_handler(commands, envs);
	else
		ft_external_command_handler(commands, *envs);
}
