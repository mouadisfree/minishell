/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:18:23 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/15 13:03:33 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*current;

	new_lst = NULL;
	current = lst;
	while (current)
	{
		new_node = ft_lstnew(f(current->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		current = current->next;
	}
	return (new_lst);
}
// #include <string.h>

// void *convert_to_uppercase(void *content)
// {
//     char *str = (char *)content;
//     for (int i = 0; str[i]; i++)
//     {
//         if (str[i] >= 'a' && str[i] <= 'z')
//             str[i] -= 32;
//     }
//     return (str);
// }

// void del_content(void *content)
// {
//     free(content);
// }

// int main(void)
// {
//     t_list *node1 = ft_lstnew(malloc(sizeof(char) * 6));
//     t_list *node2 = ft_lstnew(malloc(sizeof(char) * 6));
//     t_list *node3 = ft_lstnew(malloc(sizeof(char) * 6));

//     if (!node1 || !node2 || !node3)
//         return (1);

//     strcpy((char *)node1->content, "node1");
//     strcpy((char *)node2->content, "node2");
//     strcpy((char *)node3->content, "node3");

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     t_list *new_lst = ft_lstmap(node1, convert_to_uppercase, del_content);

//     t_list *current = new_lst;
//     while (current)
//     {
//         printf("%s\n", (char *)current->content);
//         current = current->next;
//     }

//     ft_lstclear(&new_lst, del_content);

//     return (0);
// }