/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_export_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 05:56:34 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/19 21:40:56 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	valid_name(char *name)
{
	int	i;

	i = 0;
	if (name[0] == '-')
		return (1);
	while (name[i])
	{
		if (!ft_isalpha(name[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_variable_exist(char *v, char **env)
{
	int	index;

	index = 0;
	while (env && env[index])
	{
		if (!ft_strncmp(env[index], v, ft_strlen(v)))
			return (1);
		index++;
	}
	return (-1);
}

void	define_exist_variable(char *v, char *value, char **env)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], v, ft_strlen(v)))
			index = i;
		i++;
	}
	env[index] = ft_strdup(value);
}

void	ft_norm(char **args, int index)
{
	g_exit_status = 1;
	ft_putstr_fd("bash: export:", 2);
	ft_putstr_fd(args[index], 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
	return ;
}

void	export_variable(char **args, char ***env)
{
	int		index;
	char	**args_tmp;

	index = 1;
	while (args[index])
	{
		args_tmp = ft_split(args[index], '=');
		if (!args_tmp)
		{
			g_exit_status = 1;
			ft_putstr_fd("bash: export:", 2);
			ft_putstr_fd(args[index], 2);
			ft_putstr_fd(": not a valid identifier\n", 2);
			return ;
		}
		if (valid_name(args_tmp[0]))
			ft_norm(args, index);
		else if (check_variable_exist(args_tmp[0], *env) != -1)
			define_exist_variable(args_tmp[0], args[index], *env);
		else
			add_to_env(args[index], env);
		index++;
	}
}
