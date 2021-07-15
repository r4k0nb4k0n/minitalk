/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_session_in_server.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:52:28 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/16 01:48:31 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
**	Toggle session in server.
**
**	@param	pid_t	pid_server
**	@param	char	*done_msg	The message to print when done.
**	@return	void				Nothing.
*/

void	ft_toggle_session_in_server(pid_t pid_server, char *done_msg)
{
	while (TRUE)
	{
		if (kill(pid_server, SIGUSR1) < 0)
			ft_exit_with_error_msg(PREFIX_CLIENT, ERR_FAILED_SIGNAL);
		ft_putstr_fd(INFO_SENT_SYN1_SERVER, STDOUT_FILENO);
		if (usleep(GAP_MICROSEC) < 0)
		{
			ft_putstr_fd(INFO_RECV_ACK1_SERVER, STDOUT_FILENO);
			break ;
		}
		ft_putstr_fd(ERR_PENDING_RESP, STDERR_FILENO);
	}
	ft_putstr_fd(done_msg, STDOUT_FILENO);
}
