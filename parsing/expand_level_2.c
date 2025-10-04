/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_level_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 07:54:41 by mokatfi@std       #+#    #+#             */
/*   Updated: 2025/08/20 03:19:22 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*case_of_2q(char *value, t_envs *envs, int *i, char *last_value)
{
	int	j;

	char *(get_after_v), *(value_v);
	(*i)++;
	if (value[*i] == '\0')
		return (last_value);
	value_v = my_malloc(sizeof(char *), 1);
	ft_memset(value_v, 0, 8);
	while (value[*i] && value[*i] != '\"')
	{
		if (value[*i] == '$' && ft_isalpha(value[*i + 1]))
		{
			j = 0;
			get_after_v = check_the_envir(value, i, envs, "");
			while (get_after_v[j])
				value_v = add_chr_chr(value_v, get_after_v[j], &j);
		}
		else if (value[*i] == '$' && value[*i + 1] == '?')
			value_v = ft_strjoin(value_v, case_of_exit_status("", i));
		else
			value_v = add_chr_chr(value_v, value[*i], i);
	}
	if (value[*i] == '\"')
		(*i)++;
	return (ft_strjoin(last_value, value_v));
}

char	*case_of_the_v_digit(char *value, int *i, char *last_value)
{
	int		j;
	char	*str;

	(*i) = (*i) + 2;
	j = 0;
	str = my_malloc(ft_strlen(value) + 1, 1);
	if (!str)
		return (NULL);
	while (value && value[*i] && value[*i] != '\'' && value[*i] != '\"')
	{
		str[j] = value[*i];
		i++;
		j++;
	}
	str[j] = '\0';
	str = ft_strjoin(last_value, str);
	return (str);
}
