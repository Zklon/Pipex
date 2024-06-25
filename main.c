/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrito- <lubrito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:36:15 by lubrito-          #+#    #+#             */
/*   Updated: 2024/06/25 15:27:42 by lubrito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char*argv[], char*envp[])
{
	t_px	px;

	px.ac = argc -3;
	if (argc != 5 || !argv[4][0])
		return (127);
	if (!argv[2][0 || !argv[1][0]])
		return (1);
	px.fd0 = open(argv[1], O_RDONLY);
	px.fd1 = open(argv[argc -1], O_CREAT | O_RDWR | O_TRUNC, 0664);
	check_file(argv, px);
	check_fd(px, argv);
	pipex(envp, argv, px);
	return (0);
}
