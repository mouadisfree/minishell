/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi@stdent.1337.ma <mokatfi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 04:15:58 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/09 08:34:31 by mokatfi@std      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32)
			return (0);
		i++;
	}
	return (1);
}

void	update_variable(int *position, int *findex, int number_her)
{
	*position = number_her - 1;
	*findex = number_her;
}
