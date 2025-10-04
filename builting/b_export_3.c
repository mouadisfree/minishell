/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_export_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:41:52 by mokatfi@std       #+#    #+#             */
/*   Updated: 2025/08/20 22:17:14 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	add_to_env(char *variable, char ***env)
{
	char	*v;

	int (i), (j);
	if (!ft_strchr(variable, '='))
	{
		*env = ft_realloc(*env, variable);
		return ;
	}
	v = my_malloc(ft_strlen(variable) + 1, 1);
	if (!v)
		return ;
	(1) && (i = 0, j = 0);
	while (variable && variable[i])
	{
		v[j + i] = variable[i];
		i++;
	}
	v[i] = '\0';
	*env = ft_realloc(*env, v);
}
