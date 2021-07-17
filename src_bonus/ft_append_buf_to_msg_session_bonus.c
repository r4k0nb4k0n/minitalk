/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_buf_to_msg_session_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 05:08:26 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/17 11:39:06 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_append_buf_to_msg_session(t_session *session)
{
	char	buf[2];
	char	*joined;

	buf[0] = session->buf;
	buf[1] = '\0';
	session->buf = 0;
	joined = ft_strjoin(session->msg, buf);
	if (!joined)
		return (-1);
	free(session->msg);
	session->msg = joined;
	return (0);
}
