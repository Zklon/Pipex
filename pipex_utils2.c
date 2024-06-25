/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubrito- <lubrito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:50:23 by lubrito-          #+#    #+#             */
/*   Updated: 2024/06/24 19:39:16 by lubrito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closexit(t_px px, char *argv)
{
	close(px.fd0);
	close(px.fd1);
	close(px.end[0]);
	close(px.end[1]);
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(": command not found\n", 2);
}
