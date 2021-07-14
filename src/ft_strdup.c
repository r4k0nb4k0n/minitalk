/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 22:01:08 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/14 05:16:40 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup(char *str)
{
	char	*ret;
	size_t	len_str;

	len_str = ft_strlen(str);
	ret = malloc(len_str + 1);
	if (ret != NULL)
		ft_strlcpy(ret, str, len_str + 1);
	return (ret);
}
