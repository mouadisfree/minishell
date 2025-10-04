/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:36:10 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/12 15:05:07 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// void function(unsigned int i, char *c)
// {
//     if (i % 2 == 0)
//     {
//         if (*c >= 'A' && *c <= 'Z')
//             *c += 32;
//     }
//     else
//     {
//         if (*c >= 'a' && *c <= 'z')
//             *c -= 32;
//     }
// }

// #include <stdio.h>
// int	main(void)
// {
// 	char s[] = "AbCdF";
// 	ft_striteri(s, function);
// 	printf("%s\n", s);
// 	return (0);
// }