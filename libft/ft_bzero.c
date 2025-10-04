/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:57:02 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/13 18:46:15 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
// int main()
// {
//     char arr[10] = "hellooooo";
//     ft_bzero(arr, 10);
//     int i = 0;
//     while (i < 10)
//     {
//         printf("%d", arr[i]);
//         i++;
//     }
//     return (0);
// }