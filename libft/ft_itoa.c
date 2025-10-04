/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi@stdent.1337.ma <mokatfi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:33:32 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/08 20:57:02 by mokatfi@std      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "libft.h"

unsigned int	ft_numlen(int n)
{
	int	len;

	len = 1;
	if (n > 0)
		len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	str = my_malloc((len + 1) * sizeof(char), 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	while (len-- > 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
