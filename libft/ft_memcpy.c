/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:05:07 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/13 19:25:38 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = src;
	size_t				i;

	d = dest;
	if ((!dest && !src) || n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
// int main()
// {
//     char src[] = "Hello world";
//     char dest[20];
//     ft_memcpy(dest, src, 5);
//     printf("%s\n", dest);
//     return (0);
// }