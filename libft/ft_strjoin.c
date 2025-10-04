/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:47:07 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/16 17:38:14 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = my_malloc((s1_len + s2_len + 1) * sizeof(char), 1);
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, s1, s1_len + 1);
	ft_strlcat(joined_str, s2, s1_len + s2_len + 1);
	return (joined_str);
}
