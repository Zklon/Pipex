/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrito- <lubrito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:53:10 by lubrito-          #+#    #+#             */
/*   Updated: 2024/06/24 19:33:36 by lubrito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include "Libft/libft.h"

typedef struct spx
{
	pid_t	child1;
	pid_t	child2;
	int		fd0;
	int		fd1;
	int		end[2];
	char	*cmd1;
	char	*cmd2;
	int		ac;
}		t_px;

void	pipex(char **envp, char **argv, t_px px);
void	check_file(char **argv, t_px px);
void	check_fd(t_px px, char **argv);
char	**get_path(char **envp);
char	*ft_add(char **envp, char *ag);
void	free_str(char **str);
void	ft_notfound(char *argv1, char *argv2, t_px px);
void	close1(t_px px);
void	close2(t_px px);
void	closefinal(t_px px);
void	pri_cmd(char *argv, t_px px, char **envp);
void	seg_cmd(char *argv, char **envp, int j, t_px px);
void	free_cmd(t_px px);
void	ft_child1(char **envp, char *argv2, t_px px);
void	ft_child2(char **envp, char *argv3, t_px px);
void	closexit(t_px px, char *argv);

#endif
