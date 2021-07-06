/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_str_is_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 23:12:23 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/06 23:01:05 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
**	Check the element of stack and return whether it is integer or not.
**	0. Skip the first character if it is sign(+-) character.
**	1. Iterate characters in the element.
**	1.1 If the character is not digit, return FALSE.
**	2. All characters are digits, so return TRUE.
**
**	@param	char	*elem	The element of stack.
**	@return	int		res		Wheter it is integer or not.
*/

int	ft_check_if_str_is_int(char *s)
{
	char	*p;

	p = s;
	if (ft_issign(*p))
		p++;
	while (*p)
	{
		if (!ft_isdigit(*p))
			return (FALSE);
		p++;
	}
	return (TRUE);
}
