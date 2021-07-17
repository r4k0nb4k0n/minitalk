/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:06:05 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/17 11:39:13 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/*
**	Tranform number string to int value.
**
**	@param	const char	*nptr	The target number string to transform.
**	@return	int			ret		The tranformed int value.
*/

int	ft_atoi(const char *nptr)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr && ft_issign(*nptr))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		ret = ret * 10;
		ret += (*nptr - '0') * sign;
		if (ret > 0 && sign < 0)
			return (0);
		else if (ret < 0 && sign > 0)
			return (-1);
		nptr++;
	}
	return (ret);
}
