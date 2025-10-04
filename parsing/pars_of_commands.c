/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_of_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@stdent.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:07:28 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/20 22:34:49 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_commands	*init_new_command(t_commands **list_cm)
{
	t_commands	*header_hold;
	t_commands	*new_cm;

	new_cm = my_malloc((sizeof(t_commands)), 1);
	if (!new_cm)
		return (NULL);
	ft_memset(new_cm, 0, sizeof(t_commands));
	if (list_cm && !*list_cm)
	{
		*list_cm = new_cm;
		return (new_cm);
	}
	header_hold = *list_cm;
	while (header_hold->next != NULL)
		header_hold = header_hold->next;
	header_hold->next = new_cm;
	return (new_cm);
}

void	get_the_prg_args(t_commands *new_cm, t_tokens *token)
{
	char	**args;
	int		i;

	i = 0;
	if (token->quote_type == UNAVAIBLE)
	{
		args = ft_split(token->value, ' ');
		if (args)
		{
			while (args[i])
			{
				new_cm->args = ft_realloc(new_cm->args, args[i]);
				i++;
			}
		}
	}
	else
		new_cm->args = ft_realloc(new_cm->args, token->value);
}

void	add_to_thet_redirection(t_commands *comm, t_redirection *new_red)
{
	t_redirection	*redirections;

	if (!comm->redirection)
	{
		comm->redirection = new_red;
		return ;
	}
	redirections = my_malloc((sizeof(t_redirection)), 1);
	if (!redirections)
		return ;
	else
	{
		redirections = comm->redirection;
		while (redirections->next)
			redirections = redirections->next;
		redirections->next = new_red;
	}
}

int	get_thet_redirections(t_commands *new_cm, t_tokens **_token)
{
	t_redirection	*redirection;

	redirection = my_malloc((sizeof(t_redirection)), 1);
	if (!redirection)
		return (0);
	redirection->type_quotes = (*_token)->quote_type;
	redirection->type_tokens = (*_token)->token_type;
	*_token = (*_token)->next;
	if (!*_token)
		return (0);
	if ((*_token)->token_type == REDIC_INP || (*_token)->token_type == REDIC_OUT
		|| (*_token)->token_type == APPEND || (*_token)->token_type == HERDOC)
		return (0);
	redirection->file = ft_strdup((*_token)->value);
	redirection->next = NULL;
	add_to_thet_redirection(new_cm, redirection);
	if (redirection->type_tokens == APPEND)
		new_cm->append = 1;
	if (redirection->type_tokens == HERDOC)
	{
		redirection->type_quotes = (*_token)->quote_type;
		new_cm->herdoc = 1;
	}
	return (1);
}

t_commands	*pars_and_get_commands(t_tokens *t_tokens)
{
	t_commands	*list_cm;
	t_commands	*current_cm;

	list_cm = NULL;
	while (t_tokens)
	{
		if (t_tokens->token_type == PIPE || !list_cm)
			current_cm = init_new_command(&list_cm);
		if (t_tokens->token_type == WORD)
			get_the_prg_args(current_cm, t_tokens);
		if (t_tokens->token_type == REDIC_INP
			|| t_tokens->token_type == REDIC_OUT
			|| t_tokens->token_type == APPEND || t_tokens->token_type == HERDOC)
		{
			if (!get_thet_redirections(current_cm, &t_tokens))
			{
				return (NULL);
			}
		}
		t_tokens = t_tokens->next;
	}
	return (list_cm);
}
