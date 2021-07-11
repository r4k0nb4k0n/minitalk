/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:07:53 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/12 04:45:19 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
**	Toggle connection with server.
**
**	@param	pid_t	pid_server
**	@param	char	*done_msg	The message to print when done.
**	@return	void				Nothing.
*/

void	ft_toggle_connection(pid_t pid_server, char *done_msg)
{
	int	res;
	int	i;

	res = kill(pid_server, SIGUSR1);
	if (res < 0)
		ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_SIGNAL);
	i = 0;
	while (i++ < MAX_RETRY && sleep(THRESHOLD_SEC) == 0)
		ft_putstr_fd(ERR_PENDING_RESP, STDERR_FILENO);
	if (i >= MAX_RETRY)
		ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_GET_ACK);
	ft_putstr_fd(done_msg, STDOUT_FILENO);
}

/*
**	Send the string to server with signal.
*/

void	ft_send_str_with_signal(pid_t pid_server, char *s)
{
	int	res;

	while (*s)
	{
		while ((*s)--)
		{
			res = kill(pid_server, SIGUSR2);
			if (res < 0)
				ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_SIGNAL);
		}
		res = kill(pid_server, SIGUSR1);
		if (res < 0)
			ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_SIGNAL);
		s++;
	}
}

/*
**	The client of minitalk.
**
**	0. Check if arguments are valid.
**	1. Establish connection to server.
**	2. Send the string to server.
**	3. Close connection from server.
**
**	@param	int		argc
**	@param	char	**argv
**	@return	int		status
*/

int	main(int argc, char **argv)
{
	pid_t		pid_server;
	char		*s;

	if (argc != 3 || !ft_check_if_str_is_int(argv[1]))
		ft_exit_with_error_msg(NULL, USAGE_CLIENT);
	pid_server = atoi(argv[1]);
	if (pid_server <= 0)
		ft_exit_with_error_msg(PREFIX_CLIENT, ERR_INVAL_PID_SERVER);
	s = argv[2];
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
	ft_toggle_connection(pid_server, INFO_CONN_ESTAB);
	ft_send_str_with_signal(pid_server, s);
	ft_toggle_connection(pid_server, INFO_CONN_CLOSED);
	signal(SIGUSR1, SIG_DFL);
	signal(SIGUSR2, SIG_DFL);
	return (EXIT_SUCCESS);
}
