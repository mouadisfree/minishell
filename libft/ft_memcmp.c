/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:51:52 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/13 19:15:39 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1 = s1;
	const unsigned char	*ptr2 = s2;

	while (n > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		n--;
	}
	return (0);
}
// int main()
// {
//     char str1[] = "Helloworld";
//     char str2[] = "Helloworld";
//     int result = ft_memcmp(str1, str2, 6);
//     printf("%d\n", result);
//     return (0);
// }