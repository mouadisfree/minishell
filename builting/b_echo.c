/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:41:00 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/19 06:34:13 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_check_flag(char **args)
{
	int	i;

	i = 1;
	while (args && args[i])
	{
		if (args[i][0] != '-' && args[i][1] != 'n' && args[i][2])
			break ;
		i++;
	}
	return (i);
}

void	echo_args(int n, char **args)
{
	while (args && args[n + 1])
	{
		ft_putstr_fd(ft_strjoin(args[n], " "), 1);
		n++;
	}
	ft_putstr_fd(args[n], 1);
}

int	b_echo(char **args)
{
	int	j;

	if (!args[1])
		return (printf("\n"), 0);
	if (args[1][0] != '-' && args[1][1] != 'n')
	{
		j = 1;
		while (args && args[j])
		{
			if (!args[j + 1])
				printf("%s", args[j]);
			else
				printf("%s ", args[j]);
			j++;
		}
		printf("\n");
		return (0);
	}
	j = ft_check_flag(args);
	if (!args[j])
		return (0);
	echo_args(j, args);
	return (0);
}
