/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatfi <mokatfi@stdent.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 08:06:34 by mokatfi@std       #+#    #+#             */
/*   Updated: 2025/08/20 22:33:11 by mokatfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_count_her(t_redirection *red)
{
	t_redirection	*red1;
	int				i;

	red1 = red;
	i = 0;
	while (red1)
	{
		if (red1->type_tokens == HERDOC)
			i++;
		red1 = red1->next;
	}
	return (i);
}

char	*file_creator(void)
{
	static int	i = 0;
	char		*name;
	char		*path;

	name = ft_strjoin("t_file_", ft_itoa(i + 1));
	path = ft_strjoin("/tmp/", name);
	i++;
	return (path);
}

static char	*expan_input_herdoc(char *input, t_envs *envs)
{
	int		i;
	char	*value;

	i = 0;
	value = ft_strdup("");
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] == '?')
			value = ft_strjoin(value, case_of_exit_status(value, &i));
		else if (input[i] == '$' && (ft_isalpha(input[i + 1]) || input[i + 1]
				== '_'))
			value = check_the_envir(input, &i, envs, value);
		else if (input[i] == '$' && ft_isdigit(input[i + 1]))
			value = case_of_the_v_digit(input, &i, value);
		value = add_chr_chr(value, input[i], &i);
	}
	return (value);
}

void	read_from_the_herdoc(t_redirection *reds, t_envs *envs, char *name)
{
	int		fd;
	char	*input_h;

	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	while (1)
	{
		signal(SIGINT, action_signal);
		input_h = readline("> ");
		if (!input_h)
		{
			printf("%s%s\n", EOL, reds->file);
			break ;
		}
		if (reds->file[0] == '\0' && input_h[0] == '\0')
			break ;
		if (!ft_strcmp(input_h, reds->file))
			break ;
		if (reds->type_quotes == UNAVAIBLE)
			input_h = expan_input_herdoc(input_h, envs);
		write(fd, input_h, ft_strlen(input_h));
		write(fd, "\n", 1);
	}
	close(fd);
}
