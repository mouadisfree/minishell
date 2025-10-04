/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:18:09 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/12 12:26:16 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// #include <string.h>

// void print_content(void *content)
// {
//     printf("%s\n", (char *)content);
// }

// int main(void)
// {
//     t_list *node1 = ft_lstnew(malloc(sizeof(char) * 6));
//     t_list *node2 = ft_lstnew(malloc(sizeof(char) * 6));
//     t_list *node3 = ft_lstnew(malloc(sizeof(char) * 6));

//     if (!node1 || !node2 || !node3)
//         return (1);

//     strcpy((char *)node1->content, "Node1");
//     strcpy((char *)node2->content, "Node2");
//     strcpy((char *)node3->content, "Node3");

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     ft_lstiter(node1, print_content);

//     return (0);
// }
