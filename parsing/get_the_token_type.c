/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_token_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:59:21 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/16 18:00:00 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_lst_size(t_tokens **tokens)
{
	int			i;
	t_tokens	*take;

	i = 0;
	take = *tokens;
	while (take)
	{
		take = take->next;
		i++;
	}
	return (i);
}

void	ft_lst_addback(t_tokens **list, t_tokens *new_list)
{
	t_tokens	*hold_list;

	hold_list = *list;
	while (hold_list->next)
		hold_list = hold_list->next;
	hold_list->next = new_list;
}

void	link_the_token(t_tokens **tokens, char *value, t_type_tokens token,
		t_type_quotes *quote)
{
	t_tokens	*new_token;

	new_token = my_malloc(sizeof(t_tokens), 1);
	if (!new_token)
		return ;
	new_token->value = value;
	new_token->token_type = token;
	new_token->quote_type = *quote;
	new_token->next = NULL;
	if (ft_lst_size(tokens) > 0)
		ft_lst_addback(tokens, new_token);
	else
		*tokens = new_token;
}

t_type_tokens	get_token_type(char *value)
{
	if (!ft_strcmp(value, "|"))
		return (PIPE);
	if (!ft_strcmp(value, ">>"))
		return (APPEND);
	if (!ft_strcmp(value, "<<"))
		return (HERDOC);
	if (!ft_strcmp(value, ">"))
		return (REDIC_OUT);
	if (!ft_strcmp(value, "<"))
		return (REDIC_INP);
	return (WORD);
}
