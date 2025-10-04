/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex08_find_path_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 02:26:35 by mokatfi           #+#    #+#             */
/*   Updated: 2025/08/16 09:40:41 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_if_dir(char *dir)
{
	struct stat	file;

	if (stat(dir, &file) == -1)
		return (-1);
	else if (S_ISREG(file.st_mode))
		return (0);
	else if (S_ISDIR(file.st_mode))
		return (1);
	return (1337);
}

char	*get_the_cmd_path_3(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], "PATH", 4))
			return (env[i]);
		i++;
	}
	return (NULL);
}

static	char	*check_if_file(char *cmd)
{
	int	join_len;

	join_len = 0;
	cmd[ft_strlen(cmd) - 1] = '\0';
	if (!check_if_dir(cmd))
		return (cmd = ft_strjoin(cmd, "/"), cmd = ft_strjoin(cmd,
				": Not a directory\n"), ft_putstr_fd(cmd, 2), NOT_FOUND);
	join_len = ft_strlen(ft_strjoin(cmd, NOT_FOUND));
	write(2, ft_strjoin(cmd, NOT_FOUND), join_len);
	return (g_exit_status = 127, NOT_FOUND);
}

char	*get_the_cmd_path_2(char *cmd, char **env)
{
	char *(path), *(slash), *(fullpath), **(split_path);
	int (index), (join_len);
	path = get_the_cmd_path_3(env);
	if (!path)
		return (g_exit_status = 127, ft_putstr_fd(NO_F_D, 2), NO_F_D);
	split_path = ft_split(path + 5, ':');
	index = 0;
	while (split_path && split_path[index] && cmd[0])
	{
		slash = ft_strjoin(split_path[index], "/");
		fullpath = ft_strjoin(slash, cmd);
		if (!access(fullpath, F_OK))
		{
			if (!access(fullpath, X_OK))
				return (fullpath);
			return (g_exit_status = 127, ft_putstr_fd(PER_DENI, 2), PER_DENI);
		}
		index++;
	}
	if (cmd && cmd[ft_strlen(cmd) - 1] == '/')
		return (check_if_file(cmd));
	join_len = ft_strlen(ft_strjoin(cmd, NOT_FOUND));
	write(2, ft_strjoin(cmd, NOT_FOUND), join_len);
	return (g_exit_status = 127, NOT_FOUND);
}

char	*get_the_cmd_path_1(char *cmd, char **env)
{
	if (!cmd)
		exit(0);
	if (cmd && (cmd[0] == '.' || cmd[0] == '/'))
	{
		if (check_if_dir(cmd) > 0)
		{
			ft_putstr_fd("bash: ", 2);
			ft_putstr_fd(cmd, 2);
			ft_putstr_fd(IS_DIR, 2);
			return (g_exit_status = 126, IS_DIR);
		}
		if (!access(cmd, F_OK))
		{
			if (!access(cmd, X_OK))
				return (cmd);
			return (g_exit_status = 126, ft_putstr_fd(PER_DENI, 2), PER_DENI);
		}
		return (g_exit_status = 127, ft_putstr_fd("bash: ", 2),
			ft_putstr_fd(cmd, 2), ft_putstr_fd(NO_F_D, 2), NO_F_D);
	}
	return (get_the_cmd_path_2(cmd, env));
}
