/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrito- <lubrito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:44:10 by lubrito-          #+#    #+#             */
/*   Updated: 2024/06/25 14:04:56 by lubrito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pri_cmd(char *argv, t_px px, char **envp)
{
	close1(px);
	ft_child1(envp, argv, px);
}

void	seg_cmd(char *argv, char **envp, int j, t_px px)
{
	px.child2 = fork();
	if (px.child2 == 0)
	{
		if (j == (px.ac - 1))
			closefinal(px);
		else
			close1(px);
		ft_child2(envp, argv, px);
	}
	else
		free_cmd(px);
}

void	free_cmd(t_px px)
{
	waitpid(-1, NULL, 0);
	free(px.cmd1);
	free(px.cmd2);
}

void	ft_child1(char **envp, char *argv2, t_px px)
{
	char	**args;

	args = ft_split(argv2, ' ');
	if (px.cmd1 == NULL)
	{
		free_str(args);
		free(px.cmd1);
		free(px.cmd2);
		closexit(px, argv2);
		exit(2);
	}
	if (execve(px.cmd1, args, envp) == -1)
	{
		free_str(args);
		free(px.cmd1);
		free(px.cmd2);
		closexit(px, argv2);
		exit(2);
	}
}

void	ft_child2(char **envp, char *argv3, t_px px)
{
	char	**args;

	args = ft_split(argv3, ' ');
	if (px.cmd2 == NULL)
	{
		free_str(args);
		free(px.cmd1);
		free(px.cmd2);
		closexit(px, argv3);
		exit(2);
	}
	if (execve(px.cmd2, args, envp) == -1)
	{
		free_str(args);
		free(px.cmd2);
		free(px.cmd1);
		closexit(px, argv3);
		exit(127);
	}
}
