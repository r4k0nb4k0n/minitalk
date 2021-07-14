/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:17:39 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/14 05:12:21 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	char		*dp;
	const char	*sp;

	if (src == NULL)
		return (0);
	sp = src;
	if (dst != NULL)
	{
		dp = dst;
		while (*sp && dstsize > 1)
		{
			*dp++ = *sp++;
			dstsize--;
		}
		if (dstsize >= 1)
			*dp = '\0';
	}
	while (*sp)
		sp++;
	return (sp - src);
}
