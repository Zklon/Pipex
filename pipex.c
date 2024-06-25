/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrito- <lubrito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:58:00 by lubrito-          #+#    #+#             */
/*   Updated: 2024/06/25 15:35:37 by lubrito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(char **argv, t_px px)
{
	if (access(argv[1], F_OK) == -1)
	{
		argv[1] = ft_strjoin(argv[1], ": ");
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		free(argv[1]);
		close(px.fd0);
		close(px.fd1);
		exit(1);
	}
}

void	check_fd(t_px px, char **argv)
{
	if (px.fd0 == -1 || access(argv[1], R_OK) == -1)
	{
		argv[1] = ft_strjoin(argv[1], ": ");
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		free(argv[1]);
		close(px.fd0);
		close(px.fd1);
		exit(0);
	}
	if (px.fd1 < 0)
	{
		argv[4] = ft_strjoin(argv[4], ": ");
		ft_putstr_fd(argv[4], 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		free(argv[4]);
		close(px.fd0);
		close(px.fd1);
		exit(1);
	}
}

char	**get_path(char **envp)
{
	int		i;
	char	*str;
	char	**newstr;

	i = 0;
	newstr = NULL;
	str = NULL;
	if (!envp[i])
		return (NULL);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			str = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	if (str)
	{
		newstr = ft_split(str, ':');
		free(str);
	}
	return (newstr);
}

char	*ft_add(char **envp, char *ag)
{
	char	*cmd1;
	char	**str;
	char	**args;
	char	*temp;
	int		i;

	i = 0;
	str = get_path(envp);
	if (!str)
		return (NULL);
	args = ft_split(ag, ' ');
	while (str[i])
	{
		temp = ft_strjoin(str[i], "/");
		cmd1 = ft_strjoin(temp, args[0]);
		free(temp);
		if (access(cmd1, X_OK) == 0)
			return (free_str(args), free_str(str), cmd1);
		free(cmd1);
		i++;
	}
	return (free_str(args), free_str(str), NULL);
}

void	pipex(char **envp, char **argv, t_px px)
{
	int	i;
	int	j;

	i = 2;
	j = 1;
	if (!*envp)
		return ;
	while (j < px.ac)
	{
		px.cmd1 = ft_add(envp, argv[i]);
		px.cmd2 = ft_add(envp, argv[i + 1]);
		if (!px.cmd1 || !px.cmd2)
			ft_notfound(argv[i], argv[i + 1], px);
		if (pipe(px.end) == -1)
			exit(EXIT_FAILURE);
		px.child1 = fork();
		if (px.child1 == 0)
			pri_cmd(argv[i], px, envp);
		else
			seg_cmd(argv[i +1], envp, j, px);
		i++;
		j++;
	}
}
