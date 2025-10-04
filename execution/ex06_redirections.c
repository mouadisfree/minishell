/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 01:25:36 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/20 22:00:11 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_herdoc_executor(char *herdocfile)
{
	int	fd;

	fd = open(herdocfile, O_RDONLY);
	if (fd == -1)
		return (perror("1"), g_exit_status = 2, -1);
	if (unlink(herdocfile))
		return (perror(""), -1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	ft_redirect_input_executor(t_commands *cmd, int type)
{
	char	*file;
	int		fd;

	file = cmd->redirection->file;
	if (!file || !file[0] || is_only_space(file))
		return (handle_embiguous(cmd, type));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror(""), g_exit_status = 1, -1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	ft_append_executor(t_commands *cmd, int type)
{
	char	*file;
	int		fd;

	file = cmd->redirection->file;
	if (!file || !file[0] || is_only_space(file))
		return (handle_embiguous(cmd, type));
	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (perror("open :"), g_exit_status = 1, -1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	ft_redirect_output_executor(t_commands *cmd, int type)
{
	char	*file;
	int		fd;

	file = cmd->redirection->file;
	if (!file || !file[0] || is_only_space(file))
		return (handle_embiguous(cmd, type));
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (perror("open :"), g_exit_status = 1, -1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	ft_redirections_handler(t_commands *command, int type)
{
	int				option;
	t_redirection	*redirection;

	redirection = command->redirection;
	option = 0;
	while (redirection)
	{
		if (redirection->type_tokens == HERDOC && option == 0)
		{
			option = 1;
			if (ft_herdoc_executor(command->her_file) < 0)
				return (-1);
		}
		if (redirection->type_tokens == REDIC_INP
			|| redirection->type_tokens == REDIC_OUT
			|| redirection->type_tokens == APPEND)
		{
			if (ft_redirect_in_out(command, type) < 0)
				return (-1);
		}
		redirection = redirection->next;
	}
	return (0);
}
