/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex09_signals_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 02:08:51 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/16 09:36:33 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	child_sigint(int sig)
{
	(void)sig;
	printf("\n");
	g_exit_status = 130;
	exit(g_exit_status);
}

void	child_sigquit(int sig)
{
	(void)sig;
	printf("Quit : core dumped\n");
	g_exit_status = 131;
	exit(g_exit_status);
}

void	child_signals_handler(void)
{
	signal(SIGQUIT, child_sigquit);
	signal(SIGINT, child_sigint);
}
