/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_session_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 04:28:05 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/17 11:39:37 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_init_session(t_list **sessions, pid_t pid)
{
	t_session	*session;
	t_list		*new;

	session = malloc(sizeof(t_session));
	if (!session)
		return (-1);
	session->pid = pid;
	session->status = SESS_STATUS_WAIT;
	session->msg = ft_strdup("");
	session->buf = 0;
	new = ft_lstnew((void *)session);
	if (!new || !(session->msg))
	{
		ft_free_session(session);
		return (-1);
	}
	ft_lstadd_front(sessions, new);
	return (0);
}
