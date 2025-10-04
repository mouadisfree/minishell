/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:09:48 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/13 19:10:18 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = s;
	unsigned char		ch;

	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr == ch)
		{
			return ((void *)ptr);
		}
		ptr++;
		n--;
	}
	return (NULL);
}
// int main()
// {
//     const char str[] = "Hello, World!";
//     char ch = ',';
//     size_t n = 14;
//     char *result = ft_memchr(str, ch, n);
//     if (result != NULL)
//     {
//         printf("%s\n", result);
//     } else {
//         printf("NULL\n");
//     }
//     return (0);
// }