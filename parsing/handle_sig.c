/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 04:50:25 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/19 22:28:36 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	new_promot(int sig)
{
	(void)sig;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 130;
}

void	handle_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, new_promot);
}

void	action_signal(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		g_exit_status = 131;
	}
	else
	{
		create_copy_env(NULL, 0);
		my_malloc(0, 0);
		printf("\n");
		g_exit_status = 130;
		exit(g_exit_status);
	}
}

void	handle_child_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, action_signal);
}
