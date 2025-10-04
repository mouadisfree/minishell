/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redic_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:50:12 by moouhida          #+#    #+#             */
/*   Updated: 2025/07/14 01:50:24 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*get_o(char *input, int *i)
{
	char	*value;

	value = ft_substr(input, *i, 1);
	if (input[*i] == '|' && input[*i + 1] == '|')
		return (NULL);
	if (input[*i] == '>' || input[*i] == '<')
	{
		if (input[*i + 1] == '>' || input[*i + 1] == '<' || input[*i + 1]
			== '|')
			return (NULL);
	}
	*i += 1;
	return (value);
}

char	*get_the_token(char *input, int *i, t_type_quotes *type_quotes)
{
	char	*value;

	if (!strncmp(input + *i, ">>", 2) || !strncmp(input + *i, "<<", 2))
	{
		value = ft_substr(input, *i, 2);
		if (input[*i + 2] == '>' || input[*i + 2] == '<')
			return (NULL);
		*i += 2;
	}
	else
		value = get_o(input, i);
	if (!value)
		return (NULL);
	if (input[*i] == '\'')
		*type_quotes = SINGLE_Q;
	if (input[*i] == '"')
		*type_quotes = DOUBLE_Q;
	return (value);
}

char	*get_the_word(char *input, int *i, t_type_quotes *type_quotes)
{
	char	c;
	int		start;

	start = *i;
	while (input[*i] && input[*i] != '|' && input[*i] != '>' && input[*i] != '<'
		&& input[*i] > 32)
	{
		if (input[*i] == '\'' || input[*i] == '\"')
		{
			c = input[*i];
			(*i)++;
			while (input[*i] != c && input[*i])
				(*i)++;
			if (input[*i] != c)
				return (NULL);
			if (c == '\'')
				*type_quotes = SINGLE_Q;
			if (c == '\"')
				*type_quotes = DOUBLE_Q;
		}
		(*i)++;
	}
	return (ft_substr(input, start, *i - start));
}

char	*check_type_t(char *input, int *i_input, t_type_quotes *quotes)
{
	char	*token_type;

	if (input[*i_input] == '|' || input[*i_input] == '>'
		|| input[*i_input] == '<')
		token_type = get_the_token(input, i_input, quotes);
	else
		token_type = get_the_word(input, i_input, quotes);
	if (!token_type)
		return (NULL);
	return (token_type);
}

t_tokens	*get_redirectiont_tokens(char *_input)
{
	t_tokens		*tokens;
	t_type_tokens	token;
	t_type_quotes	quote;
	char			*type;
	int				i;

	tokens = NULL;
	i = 0;
	while (_input[i])
	{
		quote = UNAVAIBLE;
		while (_input[i] <= 32 && _input[i])
			i++;
		if (!_input[i])
			break ;
		type = check_type_t(_input, &i, &quote);
		if (!type || !type[0])
			return (NULL);
		token = get_token_type(type);
		link_the_token(&tokens, type, token, &quote);
	}
	return (tokens);
}
