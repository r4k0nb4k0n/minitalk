/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 00:32:36 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/17 11:40:31 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_list	*g_sessions;

void	ft_handle_sigusr1(int signo, siginfo_t *si, void *data)
{
	t_list	*s;

	if (signo < 0 || !data || si->si_pid == 0 || si->si_pid == 1)
		return ;
	s = ft_lstfind_session_pid(g_sessions, si->si_pid);
	if (!s)
	{
		if (ft_init_session(&g_sessions, si->si_pid) < 0)
			ft_exit_with_error_msg(PREFIX_SERVER, ERR_MALLOC);
	}
	else if (((t_session *)(s->content))->status == SESS_STATUS_RECV)
	{
		((t_session *)(s->content))->status = SESS_STATUS_WAIT;
		if (ft_append_buf_to_msg_session((t_session *)(s->content)) < 0)
			ft_exit_with_error_msg(PREFIX_SERVER, ERR_MALLOC);
	}
	else if (((t_session *)(s->content))->status == SESS_STATUS_WAIT &&
		*(((t_session *)(s->content))->msg) != '\0')
	{
		ft_put_client_msg(si->si_pid, ((t_session *)(s->content))->msg);
		ft_lstdelone_session_pid(&g_sessions, si->si_pid);
	}
	if (kill(si->si_pid, SIGUSR1) < 0)
		ft_exit_with_error_msg(PREFIX_SERVER, ERR_FAILED_SIGNAL);
}

void	ft_handle_sigusr2(int signo, siginfo_t *si, void *data)
{
	t_list	*s;

	(void)signo;
	(void)data;
	if (si->si_pid == 0 || si->si_pid == 1)
		return ;
	s = ft_lstfind_session_pid(g_sessions, si->si_pid);
	if (!s)
		return ;
	if (((t_session *)(s->content))->status == SESS_STATUS_WAIT)
		((t_session *)(s->content))->status = SESS_STATUS_RECV;
	if (kill(si->si_pid, SIGUSR2) < 0)
		ft_exit_with_error_msg(PREFIX_SERVER, ERR_FAILED_SIGNAL);
	((t_session *)(s->content))->buf += 1;
}

void	ft_handle_sigint(int signo)
{
	ft_lstclear(&g_sessions, &ft_free_session);
	exit(128 + signo);
}

void	ft_install_sigactions(void)
{
	struct sigaction	s_sa_sigusr1;
	struct sigaction	s_sa_sigusr2;

	s_sa_sigusr1.sa_flags = SA_SIGINFO | SA_RESTART;
	s_sa_sigusr1.sa_sigaction = &ft_handle_sigusr1;
	sigemptyset(&(s_sa_sigusr1.sa_mask));
	sigaddset(&(s_sa_sigusr1.sa_mask), SIGUSR1);
	sigaddset(&(s_sa_sigusr1.sa_mask), SIGUSR2);
	if (sigaction(SIGUSR1, &s_sa_sigusr1, NULL) < 0)
		ft_exit_with_error_msg(PREFIX_SERVER, ERR_SIGACTION);
	s_sa_sigusr2.sa_flags = SA_SIGINFO | SA_RESTART;
	s_sa_sigusr2.sa_sigaction = &ft_handle_sigusr2;
	sigemptyset(&(s_sa_sigusr2.sa_mask));
	sigaddset(&(s_sa_sigusr2.sa_mask), SIGUSR1);
	sigaddset(&(s_sa_sigusr2.sa_mask), SIGUSR2);
	if (sigaction(SIGUSR2, &s_sa_sigusr2, NULL) < 0)
		ft_exit_with_error_msg(PREFIX_SERVER, ERR_SIGACTION);
	if (signal(SIGINT, &ft_handle_sigint) == SIG_ERR)
		ft_exit_with_error_msg(PREFIX_SERVER, ERR_SIGNAL);
}

int	main(void)
{
	pid_t	pid_server;

	pid_server = getpid();
	ft_putnbr_fd(pid_server, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	g_sessions = NULL;
	ft_install_sigactions();
	while (TRUE)
		pause();
	return (EXIT_SUCCESS);
}
