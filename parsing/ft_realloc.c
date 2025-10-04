/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:27:16 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/19 06:28:01 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**ft_realloc(char **tab, char *new_str)
{
	int		i;
	char	**return_value;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return_value = my_malloc(sizeof(char *) * (i + 2), 1);
	i = 0;
	while (tab && tab[i])
	{
		return_value[i] = ft_strdup(tab[i]);
		i++;
	}
	return_value[i] = ft_strdup(new_str);
	return_value[i + 1] = NULL;
	return (return_value);
}

int	check_commands_order(t_tokens *tokens)
{
	if (tokens->token_type == PIPE && tokens->next
		&& tokens->next->token_type == PIPE)
		return (0);
	while (tokens->next)
	{
		if (tokens->token_type == HERDOC && tokens->next
			&& tokens->next->token_type == PIPE)
			return (0);
		if (tokens->token_type == PIPE && tokens->next
			&& tokens->next->token_type == PIPE)
			return (0);
		tokens = tokens->next;
	}
	return (1);
}
