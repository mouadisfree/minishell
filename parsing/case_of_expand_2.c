/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_of_expand_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 22:37:55 by mokatfi@std       #+#    #+#             */
/*   Updated: 2025/08/18 04:29:12 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*case_of_exit_status(char *value, int *i)
{
	*i += 2;
	return (ft_strjoin(value, ft_itoa(g_exit_status)));
}

char	*get_the_normal_word(char *word, int *j, char *last_value)
{
	char	*str;

	str = ft_strdup("");
	while (word[*j] && (word[*j] != '\'') && word[*j] != '\"')
		str = add_chr_chr(str, word[*j], j);
	str = ft_strjoin(last_value, str);
	return (str);
}
