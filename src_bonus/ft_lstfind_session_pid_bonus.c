/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_session_pid_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 04:17:23 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/17 11:39:53 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_list	*ft_lstfind_session_pid(t_list *s, pid_t pid)
{
	while (s)
	{
		if (((t_session *)(s->content))->pid == pid)
			break ;
		s = s->next;
	}
	return (s);
}
