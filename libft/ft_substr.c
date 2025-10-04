/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:01:32 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/16 17:43:36 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		sub_len = s_len - start;
	else
		sub_len = len;
	substr = my_malloc((sub_len + 1) * sizeof(char), 1);
	if (!substr)
		return (NULL);
	ft_strncpy(substr, s + start, sub_len);
	substr[sub_len] = '\0';
	return (substr);
}
// int	main(void)
// {
// 	char	*result;

// 	result = ft_substr("Hello, World!", 7, 5);
// 	if (result)
// 	{
// 		printf("Substring: %s\n", result);
// 		free(result);
// 	}
// 	return (0);
// }