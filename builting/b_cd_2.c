/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:20:42 by mokatfi@std       #+#    #+#             */
/*   Updated: 2025/08/21 06:40:07 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_home(char **env)
{
	int	index;

	index = 0;
	while (env && env[index])
	{
		if (!ft_strncmp(env[index], "HOME", 4))
			return (ft_strdup(env[index] + 5));
		index++;
	}
	return (NULL);
}

int	len_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	get_the_index_v(char **env, char *name)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strcmp(ft_substr(env[i], 0, ft_strlen(env[i])
					- ft_strlen(ft_strchr(env[i], '='))), name))
			return (i);
		i++;
	}
	return (0);
}

int	set_the_value_env(char **env, char *key, char *path, int index)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (i == index)
		{
			env[i] = ft_strjoin(key, path);
			if (!env[i])
				return (perror("ft_strjoin failed"), 1);
			return (0);
		}
		i++;
	}
	return (1);
}
