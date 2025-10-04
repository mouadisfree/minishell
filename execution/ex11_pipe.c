/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex11_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 09:17:37 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/16 09:54:08 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	hh(int status)
{
	if (status == SIGINT)
	{
		signal(SIGINT, SIG_IGN);
		write(1, "\n", 1);
	}
}

void	hhh(int status)
{
	if (status == SIGQUIT)
	{
		signal(SIGQUIT, SIG_IGN);
		write(1, "Quit (core dumped)\n", 20);
	}
}

void	set_signals_parent(void)
{
	signal(SIGINT, hh);
	signal(SIGQUIT, hhh);
}

void	ft_many_commands_handler(int len, t_commands *commands, char ***env)
{
	t_pipe_data	d;

	set_signals_parent();
	init_pipe_data(len, &d, commands);
	execute_piped_loop(commands, &d, env);
	wait_for_all(d.pid, d.n_cmd);
}
