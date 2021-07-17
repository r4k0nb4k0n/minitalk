/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_session_pid_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 04:43:33 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/17 11:39:50 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_lstdelone_session_pid(t_list **sessions, pid_t pid)
{
	t_list	*prev;
	t_list	*curr;

	prev = NULL;
	curr = *sessions;
	while (curr)
	{
		if (((t_session *)(curr->content))->pid == pid)
			break ;
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return ;
	if (prev)
		prev->next = curr->next;
	else
		*sessions = curr->next;
	ft_lstdelone(curr, ft_free_session);
}
