/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:26:44 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/13 18:46:09 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
// int	main(void)
// {
// 	int *arr;
// 	size_t n = 5;
// 	arr = (int *)ft_calloc(n, sizeof(int));
// 	if (!arr)
// 	{
// 		printf("NULL\n");
// 		return (1);
// 	}
// 	printf("Values after calloc:\n");
// 	size_t i = 0;
// 	while (i < n)
// 	{
// 		printf("arr[%zu] = %d\n", i, arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }