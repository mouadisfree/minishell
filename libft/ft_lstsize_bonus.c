/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:18:38 by mokatfi           #+#    #+#             */
/*   Updated: 2025/07/13 03:36:41 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list **lst)
{
	int	count;

	count = 0;
	while (*lst)
	{
		count++;
		*lst = (*lst)->next;
	}
	return (count);
}
// #include <stdio.h>

// int main(void)
// {
//     t_list *head = ft_lstnew("Node 1");
//     t_list *node2 = ft_lstnew("Node 2");
//     t_list *node3 = ft_lstnew("Node 3");

//     head->next = node2;
//     node2->next = node3;

//     int size = ft_lstsize(head);
//     printf("size: %d\n", size);

//     free(head);
//     free(node2);
//     free(node3);

//     return (0);
// }
