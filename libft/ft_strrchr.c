/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 06:55:01 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/15 08:33:33 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	int	i;

	i = ft_strlen(str);
	while (str[i] != (char)chr)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return ((char *)str + i);
}
// int main()
// {
//     char s[] = "hello world";

//     char c = 'w';
//     printf("found : %s\n", ft_strrchr(s, c));
//     return (0);
// }