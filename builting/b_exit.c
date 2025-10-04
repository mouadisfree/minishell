/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:36:52 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/20 22:05:31 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	count_args(char **args)
{
	int	arg;

	arg = 0;
	while (args[arg])
		arg++;
	return (arg);
}

int	exit_with_digit(char *arg)
{
	int	i;

	i = 0;
	arg = ft_strtrim(arg, " ");
	if (arg[0] == '\0')
		return (free(arg), 0);
	if (arg[0] == '-' || arg[0] == '+')
	{
		if (!(ft_isdigit(arg[1])))
			return (free(arg), 0);
		i++;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (free(arg), 0);
		if (arg[i] <= 32)
			return (free(arg), 0);
		i++;
	}
	free(arg);
	return (1);
}

int	b_exit(char **args, int *l_command_exit)
{
	int	l_args;

	l_args = 0;
	l_args = count_args(args);
	if (l_args > 2)
		return (ft_putstr_fd("bash: exit: too many arguments\n", 2),
			g_exit_status = 1, 1);
	if (l_args == 1)
		return (*l_command_exit);
	if (l_args == 2)
	{
		if (exit_with_digit(args[1]))
			return ((unsigned char)ft_atoi(args[1]));
		else
			return (-1);
	}
	return (0);
}
