/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:18:31 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/12 10:18:02 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// #include <stdio.h>

// int main(void)
// {
//     t_list *node = ft_lstnew("Hello, Libft!");
//     if (node == NULL)
//     {
//         printf("Failed.\n");
//         return (1);
//     }
//     printf("%s\n", (char *)node->content);
//     free(node);
//     return (0);
// }
