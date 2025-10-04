/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 06:12:44 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/14 18:17:43 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)str + i);
}
// #include <stdio.h>

// int main()
// {
//     const char *str = "Hello, world!";
//     char ch = 'k';
//     char *result = ft_strchr(str, ch);
//     if (result != NULL)
//     {
//         printf("found: %s\n", result);
//     }
//     else
//     {
//         printf("Not found\n");
//     }
//     return (0);
// }