/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 00:32:36 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/09 19:08:15 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	pid_t	pid_server;

	pid_server = getpid();
	ft_putnbr_fd(pid_server, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	while (TRUE)
		sleep(1);
	return (EXIT_SUCCESS);
}
