/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_of_expand_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 01:50:28 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/16 17:58:41 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*get_the_normal_word_s(char *word, int *j, char *last_value)
{
	char	*str;

	(*j)++;
	str = ft_strdup("");
	ft_memset(str, 0, 8);
	while (word[*j] && word[*j] != '\'')
		str = add_chr_chr(str, word[*j], j);
	str = ft_strjoin(last_value, str);
	return (str);
}

char	*get_the_variable_value(t_envs *envs, char *str)
{
	while (envs)
	{
		if (!ft_strncmp(envs->name, str, ft_strlen(str)))
			return (envs->paths);
		envs = envs->next;
	}
	return (ft_strdup(""));
}

char	*add_chr_chr(char *value, char c, int *j)
{
	char	*str;
	int		i;

	str = my_malloc(ft_strlen(value) + 2, 1);
	i = 0;
	while (value[i] != '\0')
	{
		str[i] = value[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	(*j)++;
	return (str);
}

void	ft_value(char *value)
{
	value = ft_strdup("");
	ft_memset(value, 0, 8);
}

char	*check_the_envir(char *str, int *i, t_envs *en, char *last_value)
{
	int		j;
	char	*value;
	char	*get;

	(*i)++;
	j = (*i);
	while (str[*i] && str[*i] != ' ' && (ft_isalpha(str[*i]) || str[*i] == '_'))
		(*i)++;
	get = my_malloc(*i + 1, 1);
	if (!get)
		return (NULL);
	(*i) = j;
	j = 0;
	while (str[*i] && str[*i] != ' ' && (ft_isalpha(str[*i]) || str[*i] == '_'))
	{
		get[j] = str[*i];
		(*i)++;
		j++;
	}
	get[j] = '\0';
	value = get_the_variable_value(en, get);
	if (!value)
		ft_value(value);
	value = ft_strjoin(last_value, value);
	return (value);
}
