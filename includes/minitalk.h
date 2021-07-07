/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:04:22 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/08 00:42:34 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Get include-guarded.
*/

#ifndef MINITALK_H
# define MINITALK_H

/*
**	Include header files in need.
**	<unistd.h>
**	.. ssize_t write(int filedes, const void *buf, size_t nbyte);
**	.. pid_t getpid(void);
**	<stdlib.h>
**	.. void exit(int status);
**	.. EXIT_SUCCESS
**	.. EXIT_FAILURE
**	<signal.h>
**	.. int kill(pid_t pid, int sig);i
**	.. SIGUSR1
**	.. SIGUSR2
*/

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

/*
**	Define msg macros in need.
*/

# define PREFIX_SERVER "server"
# define PREFIX_CLIENT "client"
# define USAGE_CLIENT "usage: ./client server_PID string_that_should_be_sent\n"
# define ERR_INVAL_PID_SERVER "Invalid server PID\n"
# define ERR_PENDING_RESP "Pending response from server\n"

/*
**	Define macros in need.
*/

# define TRUE 1
# define FALSE 0

/*
**	ft_strlen.c
*/

int		ft_strlen(char *s);

/*
**	ft_character.c
*/

int		ft_isdigit(char c);
int		ft_issign(char c);
int		ft_isspace(char c);

/*
**	ft_check_if_str_is_int.c
*/

int		ft_check_if_str_is_int(char *s);

/*
**	ft_atoi.c
*/

int		ft_atoi(const char *nptr);

/*
**	ft_error.c
*/

void	ft_print_error(char *prefix, char *msg);
void	ft_exit_if_null(void *target);
void	ft_exit_with_syserr(char *prefix);
void	ft_exit_with_error_msg(char *prefix, char *msg);

/*
**	ft_putchar_fd.c
*/

void	ft_putchar_fd(char c, int fd);

/*
**	ft_putstr_fd.c
*/

void	ft_putstr_fd(char *s, int fd);

/*
**	ft_putnbr_fd.c
*/

void	ft_putnbr_fd(int n, int fd);

#endif
