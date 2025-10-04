/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:42:45 by moouhida          #+#    #+#             */
/*   Updated: 2025/08/20 05:32:24 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	red_to_home(char **env)
{
	char	path[1337];
	int		index_pwd;
	int		index_old;
	char	*pa;

	index_pwd = get_the_index_v(env, "PWD");
	index_old = get_the_index_v(env, "OLDPWD");
	pa = get_home(env);
	if (!pa)
		return (ft_putstr_fd("cd : HOME not  set!\n", 2), g_exit_status = 1, 1);
	if (chdir(pa) != 0)
		return (perror("faile to return (home)\n"), 1);
	if (!getcwd(path, sizeof(path)))
		return (perror("failed to get the path/\n"), 1);
	if (!index_pwd)
		return (perror("no env set for PWD\n"), 1);
	if (set_the_value_env(env, "PWD=", path, index_pwd))
		return (perror("the env unset\n"), 1);
	if (set_the_value_env(env, "OLDPWD=", path, index_old))
		return (perror("the env unset\n"), 1);
	return (0);
}

int	failed_dir(char *dir)
{
	if (ft_strcmp(dir, ".") != 0)
	{
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putstr_fd(" No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

int	go_back(char *dir, char **env)
{
	char	last_dir[1337];
	char	*pwd;
	int		index_oldpwd;
	int		index_new;

	if (ft_strcmp(dir, ".") == 0)
		return (failed_dir(dir));
	index_oldpwd = get_the_index_v(env, "OLDPWD");
	index_new = get_the_index_v(env, "PWD");
	pwd = env[index_new];
	if (chdir(dir) != 0)
		return (perror("chdir : failed\n"), 1);
	if (!getcwd(last_dir, sizeof(last_dir)))
		return (perror("getcwd : failed\n"), 1);
	if (!index_new || !index_oldpwd)
		return (perror("the  envirement not set\n"), 1);
	set_the_value_env(env, "OLDPWD=", pwd + 5, index_oldpwd);
	set_the_value_env(env, "PWD=", last_dir, index_new);
	return (0);
}

int	red_to_path(char *dir, char **env)
{
	char	*old_pwd;
	char	n_pwd[1337];
	int		index_oldpwd;
	int		index_new;

	index_oldpwd = get_the_index_v(env, "OLDPWD");
	index_new = get_the_index_v(env, "PWD");
	old_pwd = env[index_new];
	if (!ft_strncmp(dir, ".", 1))
		return (go_back(dir, env));
	if (chdir(dir) != 0)
		return (ft_putstr_fd("No such file or directory\n", 2),
			g_exit_status = 1, 1);
	if (!getcwd(n_pwd, sizeof(n_pwd)))
		return (perror("getcwd failed\n"), 1);
	if (index_new == 0 || index_oldpwd == 0)
		return (perror("not set: "), 1);
	set_the_value_env(env, "OLDPWD=", old_pwd + 3, index_oldpwd);
	set_the_value_env(env, "PWD=", n_pwd, index_new);
	return (0);
}

int	b_cd(char **args, char **env)
{
	int	len;

	len = len_args(args);
	if (len == 3)
		return (ft_putstr_fd("bash: cd: too many arguments\n", 2),
			g_exit_status = 1, 1);
	if (len == 1)
		red_to_home(env);
	if (len == 2)
		red_to_path(args[1], env);
	return (0);
}
