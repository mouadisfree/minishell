/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:50:19 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/14 18:06:49 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
// int main()
// {
//     char arr[10] = "hello";
//     char *ptr = ft_memset(arr, 'm', 10);
//     int i = 0;
//     while (i < 10)
//     {
//         printf("%c ", ptr[i]);
//         i++;
//     }
// 	printf("\n");
//     return (0);
// }
