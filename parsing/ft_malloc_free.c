/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 06:20:47 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/16 08:09:13 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*my_malloc(size_t size, int mode)
{
	static t_list	*head;
	t_list			*new;
	void			*addr;

	addr = NULL;
	if (mode == 1)
	{
		addr = malloc(size);
		if (!addr)
		{
			ft_putstr_fd("malloc: failed", 2);
			my_malloc(0, 0);
			exit(1);
		}
		new = ft_lstnew(addr);
		ft_lstadd_back(&head, new);
	}
	if (mode == 0)
	{
		ft_lstclear(&head, free);
		head = NULL;
	}
	return (addr);
}
