/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrito- <lubrito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:41:54 by lubrito-          #+#    #+#             */
/*   Updated: 2024/06/25 14:04:54 by lubrito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_notfound(char *argv1, char *argv2, t_px px)
{
	close(px.fd0);
	close(px.fd1);
	ft_putstr_fd(argv1, 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_putstr_fd(argv2, 2);
	ft_putstr_fd(": command not found\n", 2);
	free(px.cmd1);
	free(px.cmd2);
	exit(127);
}

void	close1(t_px px)
{
	close(px.end[0]);
	dup2(px.fd0, STDIN_FILENO);
	dup2(px.end[1], STDOUT_FILENO);
	close(px.end[1]);
}

void	close2(t_px px)
{
	dup2(px.end[0], STDIN_FILENO);
	dup2(px.end[1], STDOUT_FILENO);
	close(px.end[1]);
}

void	closefinal(t_px px)
{
	dup2(px.end[0], STDIN_FILENO);
	close(px.end[0]);
	dup2(px.fd1, STDOUT_FILENO);
	close(px.end[1]);
}
