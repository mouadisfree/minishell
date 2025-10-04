/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 04:34:05 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/18 04:06:44 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_swp(char **str1, char **str2)
{
	char	*hold;

	hold = *str2;
	*str2 = *str1;
	*str1 = hold;
}

static void	ft_export(char **env)
{
	char	*name_v;
	char	*value_v;
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strchr(env[i], '='))
			printf("declare -x %s\n", env[i]);
		else
		{
			value_v = ft_strchr(env[i], '=');
			name_v = ft_substr(env[i], 0, ft_strlen(env[i])
					- ft_strlen(value_v));
			printf("declare -x %s=\"%s\"\n", name_v, value_v + 1);
		}
		i++;
	}
}

static void	export_normal(char **env)
{
	int	i;

	i = 0;
	while (env[i + 1])
	{
		if (ft_strcmp(env[i], env[i + 1]) > 0)
		{
			ft_swp(&env[i], &env[i + 1]);
			i = 0;
		}
		else
			i++;
	}
	ft_export(env);
}

int	b_export(char **args, char ***env)
{
	int	len;

	len = len_args(args);
	if (len == 1)
		return (export_normal(*env), 0);
	export_variable(args, env);
	return (0);
}
