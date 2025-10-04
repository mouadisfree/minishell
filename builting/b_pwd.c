/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi@stdent.1337.ma <mokatfi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:37:05 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/08 20:45:31 by mokatfi@std      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	get_the_index_var(char **env, char *name)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == name[0] && env[i][1] == name[1]
			&& env[i][2] == name[2])
			return (i);
		i++;
	}
	return (0);
}

int	b_pwd(char **env)
{
	int		x;
	char	*c_dir;

	c_dir = getcwd(NULL, 0);
	x = get_the_index_var(env, "PWD");
	if (x > 0)
		printf("%s\n", env[x] + 4);
	else
	{
		printf("%s\n", c_dir);
		free(c_dir);
	}
	return (0);
}
