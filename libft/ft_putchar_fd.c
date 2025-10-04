/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:58:40 by mokatfi           #+#    #+#             */
/*   Updated: 2024/11/15 10:51:11 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
//     int fd = open("Mouad.txt", O_WRONLY | O_CREAT, 0644);
// 	if (fd == -1)
// 	{
//         write(2, "Error opening the file\n", 23);
//         return (1);
//     }
// 	write(fd, "Hello, file descriptor!\n", 24);
//     close(fd);
//     ft_putchar_fd('A', 1);
//     ft_putchar_fd('\n', 1);
//     ft_putchar_fd('B', 2);
//     ft_putchar_fd('\n', 2);
//     return (0);
// }