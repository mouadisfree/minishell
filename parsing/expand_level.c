/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@stdent.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:33:39 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/20 22:11:28 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*case_of_variable_with_quotes(char *value, int *i, char *new_value)
{
	char	c;
	char	*str;

	int (j), (k);
	c = value[*i];
	(*i)++;
	j = (*i);
	while (value[*i] && value[*i] != c)
		(*i)++;
	k = (*i) - j;
	str = my_malloc((k + 1), 1);
	(*i) = j;
	j = 0;
	while (value[*i] && value[*i] != c)
	{
		str[j] = value[*i];
		j++;
		(*i)++;
	}
	str[j] = '\0';
	str = ft_strjoin(new_value, str);
	return (str);
}

char	*get_the_token_value_by_expand(char *value, char *new_value,
		t_envs *env, int *i)
{
	if (value[*i] == '\'')
		new_value = get_the_normal_word_s(value, i, new_value);
	else if (value[*i] == '\"')
		new_value = case_of_2q(value, env, i, new_value);
	else if (value[*i] == '$' && ft_isdigit(value[*i + 1]))
		new_value = case_of_the_v_digit(value, i, new_value);
	else if (value[*i] == '$' && (ft_isalpha(value[*i + 1])
			|| value[*i + 1] == '_'))
		new_value = check_the_envir(value, i, env, new_value);
	else if (value[*i] == '$' && value[*i + 1] == '?')
		new_value = ft_strjoin(new_value, case_of_exit_status(new_value, i));
	else if (value[*i] == '$' && (value[*i + 1] == '\''
			|| value[*i + 1] == '\"'))
		new_value = case_of_variable_with_quotes(value, i, new_value);
	else
		new_value = add_chr_chr(new_value, value[*i], i);
	return (new_value);
}

char	*get_the_delimiter(char *value)
{
	char	*delimiter;

	int (i), (j), (x);
	i = 0;
	j = 0;
	if (ft_strlen(value) == 2 && value[0] == '\"' && value[1] == '\"')
		return (ft_strdup(""));
	delimiter = my_malloc((ft_strlen(value) + 1), 1);
	if (!delimiter)
		return (NULL);
	while (value[i])
	{
		x = 0;
		if (value[i] != '\'' && value[i] != '\"')
		{
			delimiter[j] = value[i];
			x = 1;
		}
		if (x)
			j++;
		i++;
	}
	delimiter[j] = '\0';
	return (delimiter);
}

char	*get_the_value(char *value, t_envs *env, int *is_herdoc)
{
	int		i;
	char	*value1;

	i = 0;
	value1 = ft_strdup("");
	if (!value)
		return (NULL);
	if (*is_herdoc == 1)
	{
		value1 = get_the_delimiter(value);
		*is_herdoc = 0;
		return (value1);
	}
	while (value[i])
		value1 = get_the_token_value_by_expand(value, value1, env, &i);
	return (value1);
}

void	expand_level_tokens(t_envs *envi, t_tokens *tokens)
{
	int	is_herdoc;

	is_herdoc = 0;
	while (tokens)
	{
		if (tokens->token_type == HERDOC)
			is_herdoc = 1;
		if (tokens->token_type == WORD)
			tokens->value = get_the_value(tokens->value, envi, &is_herdoc);
		tokens = tokens->next;
	}
	g_exit_status = 0;
}
