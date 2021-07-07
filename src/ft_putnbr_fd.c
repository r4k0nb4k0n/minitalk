/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:45:35 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/08 00:40:46 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	un = n;
	if (n < 0)
		un = -n;
	if (-9 <= n && n <= 9)
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		ft_putchar_fd(un + '0', fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((un % 10) + '0', fd);
}
