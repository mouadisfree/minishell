/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@stdent.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:12:52 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/16 01:13:11 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_how_many_commands(t_commands *commands)
{
	int			counter;
	t_commands	*tmp;

	counter = 0;
	tmp = commands;
	while (tmp)
	{
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}
