/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:33:45 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/14 13:29:29 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;
	size_t				i;

	d = (unsigned char *)dest;
	if ((!dest && !src) || len == 0)
		return (dest);
	if (d < s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	return (dest);
}
// int main()
// {
//     char str[] = "HelloWorld";
//     printf("%s\n", str);
//     ft_memmove(str, str + 5, 5);
//     printf("%s\n", str);
//     return (0);
// }