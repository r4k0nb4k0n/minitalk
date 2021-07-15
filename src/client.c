/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:07:53 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/15 20:07:43 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_session	g_session;
char		*g_msg_last;

/*
**	Handler of SIGUSR1.
**
**	@param	int			signo
**	@param	siginfo_t	*siginfo
**	@param	void		*data
**	@return	void		Nothing.
*/

void	ft_handle_sigusr1(int signo, siginfo_t *siginfo, void *data)
{
	(void)signo;
	(void)siginfo;
	(void)data;

	if (g_session.status == SESS_STATUS_WAIT)
	{
		if (*(g_session.msg))
			g_session.status = SESS_STATUS_RECV;
	}
	else if (g_session.status == SESS_STATUS_RECV)
	{
		if (*(g_session.msg) == '\0' && g_session.msg != g_msg_last)
			(g_session.msg)++;
		if (g_session.msg == g_msg_last)
			g_session.status = SESS_STATUS_WAIT;
	}
}

/*
**	Handler of SIGUSR2.
**
**	@param	int			signo
**	@param	siginfo_t	*siginfo
**	@param	void		*data
**	@return	void		Nothing.
*/

void	ft_handle_sigusr2(int signo, siginfo_t *siginfo, void *data)
{
	(void)signo;
	(void)siginfo;
	(void)data;

	if (*(g_session.msg))
		*(g_session.msg) -= 1;
}

void	ft_install_sigactions(void)
{
	struct sigaction	s_sa_sigusr1;
	struct sigaction	s_sa_sigusr2;

	s_sa_sigusr1.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	s_sa_sigusr1.sa_sigaction = &ft_handle_sigusr1;
	sigemptyset(&(s_sa_sigusr1.sa_mask));
	sigaddset(&(s_sa_sigusr1.sa_mask), SIGUSR1);
	sigaddset(&(s_sa_sigusr1.sa_mask), SIGUSR2);
	if (sigaction(SIGUSR1, &s_sa_sigusr1, NULL) < 0)
		ft_exit_with_error_msg(PREFIX_SERVER, ERR_SIGACTION);
	s_sa_sigusr2.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	s_sa_sigusr2.sa_sigaction = &ft_handle_sigusr2;
	sigemptyset(&(s_sa_sigusr2.sa_mask));
	sigaddset(&(s_sa_sigusr2.sa_mask), SIGUSR1);
	sigaddset(&(s_sa_sigusr2.sa_mask), SIGUSR2);
	if (sigaction(SIGUSR2, &s_sa_sigusr2, NULL) < 0)
		ft_exit_with_error_msg(PREFIX_SERVER, ERR_SIGACTION);
}

/*
**	Send the string to server with signal.
*/

void	ft_send_str_with_signal(void)
{
	char	*p;

	while (*(g_session.msg))
	{
		while (*(g_session.msg))
		{
			if (kill(g_session.pid, SIGUSR2) < 0)
				ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_SIGNAL);
			usleep(GAP_MICROSEC);
		}
		p = g_session.msg;
		while (p == g_session.msg)
		{
			if (kill(g_session.pid, SIGUSR1) < 0)
				ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_SIGNAL);
			usleep(GAP_MICROSEC);
		}
		/*if (kill(g_session.pid, SIGUSR1) < 0)
			ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_SIGNAL);
		usleep(GAP_MICROSEC);*/
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
	pid_t	pid_server;
	char	*s;

	if (argc != 3 || !ft_check_if_str_is_int(argv[1]))
		ft_exit_with_error_msg(NULL, USAGE_CLIENT);
	pid_server = atoi(argv[1]);
	if (pid_server <= 0)
		ft_exit_with_error_msg(PREFIX_CLIENT, ERR_INVAL_PID_SERVER);
	s = argv[2];
	g_session.pid = pid_server;
	g_session.status = SESS_STATUS_WAIT;
	g_session.msg = s;
	g_msg_last = s;
	while (*g_msg_last)
		g_msg_last++;
	ft_install_sigactions();
	ft_toggle_session_in_server(pid_server, INFO_CONN_ESTAB);
	ft_send_str_with_signal();
	ft_toggle_session_in_server(pid_server, INFO_CONN_CLOSED);
	return (EXIT_SUCCESS);
}
