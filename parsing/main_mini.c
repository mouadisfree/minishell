/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:59:38 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/19 22:31:13 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		g_exit_status = 0;

void	ft_free(char **str, unsigned int n)
{
	while (n--)
	{
		free(str[n]);
		str[n] = NULL;
	}
	free(str);
	str = NULL;
}

char	**create_copy_env(char **env, int option)
{
	static char	**copy = NULL;
	static int	index;

	index = 0;
	if (option == 1)
	{
		while (env && env[index])
			index++;
		copy = malloc(sizeof(char *) * (index + 1));
		if (!copy)
			return (NULL);
		index = 0;
		while (env && env[index])
		{
			copy[index] = env[index];
			index++;
		}
		copy[index] = NULL;
	}
	else
		ft_free(copy, index);
	return (copy);
}

int	main(int ac, char **av, char **envir)
{
	char	**copy_env;

	copy_env = NULL;
	if (ac > 1)
		return (ft_putstr_fd("the program should run with one arg", 2), 1);
	ft_mouad_o_mouaad();
	(void)av;
	copy_env = create_copy_env(envir, 1);
	if (!copy_env)
		return (1);
	handle_signals();
	terminal_process(copy_env);
	clear_history();
	create_copy_env(NULL, 0);
	my_malloc(0, 0);
	exit(g_exit_status);
}
