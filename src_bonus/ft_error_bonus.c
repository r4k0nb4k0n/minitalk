/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:46:54 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/17 11:39:30 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/*
**	Print error message in stderr.
**
**	@param	char	*prefix	The prefix string.
**	@param	char	*msg	The error message.
**	@return	void			Nothing.
*/

void	ft_print_error(char *prefix, char *msg)
{
	if (prefix)
	{
		write(STDERR_FILENO, prefix, ft_strlen(prefix));
		write(STDERR_FILENO, COLON_SPACE, ft_strlen(COLON_SPACE));
	}
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
}

/*
**	Exit with error message.
**
**	@param	char	*prefix	The prefix string.
**	@param	char	*msg	The error message.
**	@return	void			Nothing.
*/

void	ft_exit_with_error_msg(char *prefix, char *msg)
{
	ft_print_error(prefix, msg);
	exit(EXIT_FAILURE);
}
