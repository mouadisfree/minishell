/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:59:54 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/19 06:40:13 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	terminal_process(char **env)
{
	char	*input;

	while (1)
	{
		signal(SIGINT, new_promot);
		input = readline("\033[1;34mMINISHELL-1337$ \033[0m");
		if (!input)
			return (printf("exit\n"), 0);
		if (ft_strlen(input) > 0 && !is_only_space(input))
		{
			add_history(input);
			check_input(input, &env);
		}
	}
	return (0);
}

t_envs	*new_env_version(char **env)
{
	int		i;
	char	*name;
	char	*paths;
	t_envs	*copy_env;

	i = 0;
	copy_env = my_malloc(sizeof(t_envs), 1);
	if (!copy_env)
		return (NULL);
	copy_env = NULL;
	while (env[i])
	{
		paths = ft_strchr(env[i], '=');
		if (paths)
		{
			name = ft_substr(env[i], 0, ft_strlen(env[i]) - ft_strlen(paths));
			paths++;
			ft_lstadd_env(&copy_env, name, paths);
		}
		i++;
	}
	return (copy_env);
}

void	check_input(char *input, char ***env)
{
	t_tokens	*tokens;
	t_commands	*commands;
	t_envs		*envi;

	tokens = get_redirectiont_tokens(input);
	if (!tokens)
	{
		g_exit_status = 2;
		my_malloc(0, 0);
		ft_putstr_fd("bash: syntax error near unexpected token\n", 2);
		return ;
	}
	envi = new_env_version(*env);
	expand_level_tokens(envi, tokens);
	commands = pars_and_get_commands(tokens);
	if (!commands || !check_commands_order(tokens))
	{
		ft_putstr_fd("bash: syntax error near unexpected token \n", 2);
		my_malloc(0, 0);
		g_exit_status = 2;
		return ;
	}
	if (!check_the_herdoc(commands, envi))
		execution_start(commands, env);
}
