/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:07:53 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/07 00:25:24 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
**	The client of minitalk.
**
**	@param	int		argc
**	@param	char	**argv
**	@return	int		status
*/

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	char	*s;

	if (argc != 3 || !ft_check_if_str_is_int(argv[1]))
		ft_exit_with_error_msg(NULL, USAGE_CLIENT);
	pid_server = atoi(argv[1]);
	if (pid_server <= 0)
		ft_exit_with_error_msg(PREFIX_CLIENT, ERR_INVAL_PID_SERVER);
	s = argv[2];
	while (*s)
	{
		kill(pid_server, SIGUSR1);
		if (sleep(1) == 0)
			ft_exit_with_error_msg(PREFIX_CLIENT, ERR_PENDING_RESP);
		s++;
	}
	return (EXIT_SUCCESS);
}
