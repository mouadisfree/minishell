/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:18:16 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/15 12:07:56 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
// #include <stdio.h>

// int main(void)
// {
//     t_list *head = ft_lstnew("Node 1");
//     t_list *node2 = ft_lstnew("Node 2");
//     t_list *node3 = ft_lstnew("Node noura");

//     head->next = node2;
//     node2->next = node3;

//     t_list *last = ft_lstlast(head);
//     if (last)
//         printf("Last node content: %s\n", (char *)last->content);

//     free(head);
//     free(node2);
//     free(node3);

//     return (0);
// }
