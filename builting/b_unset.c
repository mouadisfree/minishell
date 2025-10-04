/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi@stdent.1337.ma <mokatfi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:37:17 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/08 20:47:38 by mokatfi@std      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_remove_v(char *name, char **env)
{
	int	index_v;
	int	index;

	index_v = get_the_index_v(env, name);
	index = 0;
	while (env && env[index])
	{
		if (index == index_v)
		{
			while (env && env[index + 1])
			{
				env[index] = env[index + 1];
				index++;
			}
			env[index] = NULL;
			return ;
		}
		index++;
	}
}

int	b_unset(char **args, char **env)
{
	int	len;
	int	i;

	i = 0;
	len = len_args(args);
	if (len == 1)
		return (1);
	while (args && i < len)
	{
		if (check_variable_exist(args[i], env))
			ft_remove_v(args[i], env);
		i++;
	}
	return (0);
}
