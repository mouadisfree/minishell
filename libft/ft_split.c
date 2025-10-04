/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:03:15 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/16 17:43:48 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "libft.h"

int	ft_w_counter(char const *s, char c)
{
	int	i;
	int	k;
	int	counter;

	i = 0;
	k = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == c)
			k = 0;
		else
		{
			if (k == 0)
				counter++;
			k = 1;
		}
		i++;
	}
	return (counter);
}

char	**ft_freesplit(char **a)
{
	int	i;

	if (!a)
		return (NULL);
	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**a;

	int (i), (k), (start);
	if (!s)
		return (NULL);
	a = my_malloc((ft_w_counter(s, c) + 1) * sizeof(char *), 1);
	if (!a)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			a[k++] = ft_substr(s, start, i - start);
		if (!a)
			ft_freesplit(a);
	}
	a[k] = NULL;
	return (a);
}
