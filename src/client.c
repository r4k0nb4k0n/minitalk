/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:07:53 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/14 18:49:36 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
**	Handler of SIGUSR1.
**
**	@param	int	signo
**	@return	void		Nothing.
*/

void	ft_handle_sigusr1(int signo, siginfo_t *siginfo, void *data)
{
	(void)signo;
	(void)siginfo;
	(void)data;
}

void	ft_install_sigaction(void)
{
	struct sigaction	s_sa_sigusr1;

	s_sa_sigusr1.sa_flags = SA_RESTART | SA_NODEFER;
	s_sa_sigusr1.sa_sigaction = &ft_handle_sigusr1;
	sigemptyset(&(s_sa_sigusr1.sa_mask));
	sigaddset(&(s_sa_sigusr1.sa_mask), SIGUSR1);
	if (sigaction(SIGUSR1, &s_sa_sigusr1, NULL) < 0)
		ft_exit_with_error_msg(PREFIX_SERVER, ERR_SIGACTION);
}

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

	i = 0;
	while (i < MAX_RETRY)
	{
		res = kill(pid_server, SIGUSR1);
		if (res < 0)
			ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_SIGNAL);
		if (usleep(GAP_MICROSEC) < 0)
			break;
		ft_putstr_fd(ERR_PENDING_RESP, STDERR_FILENO);
		i++;
	}
	if (i >= MAX_RETRY)
		ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_GET_ACK);
	ft_putstr_fd(done_msg, STDOUT_FILENO);
}

/*
**	Send the string to server with signal.
*/

void	ft_send_str_with_signal(pid_t pid_server, char *s)
{
	while (*s)
	{
		while (*s)
		{
			if (kill(pid_server, SIGUSR2) < 0)
				ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_SIGNAL);
			if (usleep(GAP_MICROSEC) < 0)
				(*s)--;
		}
		while (TRUE)
		{
			if (kill(pid_server, SIGUSR1) < 0)
				ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_SIGNAL);
			if (usleep(GAP_MICROSEC) < 0)
				break ;
		}
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
	ft_install_sigaction();
	ft_toggle_connection(pid_server, INFO_CONN_ESTAB);
	ft_send_str_with_signal(pid_server, s);
	ft_toggle_connection(pid_server, INFO_CONN_CLOSED);
	signal(SIGUSR1, SIG_DFL);
	return (EXIT_SUCCESS);
}
