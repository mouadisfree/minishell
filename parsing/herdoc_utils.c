/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@stdent.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 04:55:27 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/20 22:49:21 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	wait_for_child(int pid, int *signal_detect)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	waitpid(pid, &status, 0);
	*signal_detect = 0;
	if ((WEXITSTATUS(status) == 130 && WIFEXITED(status))
		|| (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT))
	{
		g_exit_status = 130;
		*signal_detect = 1;
		return ;
	}
}

int	case_of_cmd_herdoc(t_redirection *reds, t_envs *envs, char **files,
		int index_f)
{
	t_redirection	*red;

	red = reds;
	int (pid), (signal_detected);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, action_signal);
		while (red)
		{
			if (red->type_tokens == HERDOC)
			{
				read_from_the_herdoc(red, envs, files[index_f]);
				index_f++;
			}
			red = red->next;
		}
		my_malloc(0, 0);
		exit(0);
	}
	wait_for_child(pid, &signal_detected);
	return (signal_detected);
}

void	create_her_doc_files(t_commands *commands, char ***files)
{
	t_commands		*t_commands;
	t_redirection	*reds;

	*files = NULL;
	t_commands = commands;
	while (t_commands)
	{
		reds = t_commands->redirection;
		while (reds)
		{
			if (reds->type_tokens == HERDOC)
			{
				*files = ft_realloc(*files, file_creator());
			}
			reds = reds->next;
		}
		t_commands = t_commands->next;
	}
}

void	ft_init_int(int *f_index, int *signal_detect, int *position_file,
		int *num_of_her)
{
	*f_index = 0;
	*signal_detect = 0;
	*position_file = 0;
	*num_of_her = 0;
}

int	check_the_herdoc(t_commands *commands, t_envs *envs)
{
	t_redirection	*red;
	char			**files;
	t_commands		*t_commands;

	int (num_of_her), (f_index), (signal_detect), (position_file);
	t_commands = commands;
	create_her_doc_files(t_commands, &files);
	ft_init_int(&f_index, &signal_detect, &position_file, &num_of_her);
	while (t_commands)
	{
		red = t_commands->redirection;
		num_of_her = ft_count_her(red);
		if (num_of_her > 16)
			return (ft_putstr_fd(HERDOC_MAX, 2), 1);
		else if (num_of_her > 0)
			signal_detect = case_of_cmd_herdoc(red, envs, files, position_file);
		if (num_of_her > 0)
			t_commands->her_file = ft_strdup(files[f_index + num_of_her - 1]);
		if (signal_detect)
			return (1);
		if (num_of_her > 0)
			update_variable(&position_file, &f_index, num_of_her);
		t_commands = t_commands->next;
	}
	return (0);
}
