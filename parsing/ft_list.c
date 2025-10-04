/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi@stdent.1337.ma <mokatfi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:33:05 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/09 08:34:01 by mokatfi@std      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_lstadd_env(t_envs **envire, char *name, char *paths)
{
	t_envs	*envire1;
	t_envs	*envire2;

	envire1 = my_malloc(sizeof(t_envs), 1);
	envire2 = my_malloc(sizeof(t_envs), 1);
	if (!envire1 || !envire)
		return ;
	envire1 = *envire;
	envire2->name = name;
	envire2->paths = paths;
	envire2->next = NULL;
	if (!*envire)
		*envire = envire2;
	else
	{
		while (envire1->next)
			envire1 = envire1->next;
		envire1->next = envire2;
	}
}
