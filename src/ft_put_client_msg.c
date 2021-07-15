/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_client_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 02:43:35 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/16 02:46:33 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_put_client_msg(pid_t pid, char *msg)
{
	ft_putnbr_fd(pid, STDOUT_FILENO);
	ft_putstr_fd(COLON_SPACE, STDOUT_FILENO);
	ft_putstr_fd(msg, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
