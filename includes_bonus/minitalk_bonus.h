/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:04:22 by hyechoi           #+#    #+#             */
/*   Updated: 2021/07/17 11:44:32 by hyechoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Get include-guarded.
*/

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

/*
**	Include header files in need.
**	<unistd.h>
**	.. ssize_t write(int filedes, const void *buf, size_t nbyte);
**	.. pid_t getpid(void);
**	.. int pause(void);
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

# define COLON_SPACE ": "
# define PREFIX_SERVER "server"
# define PREFIX_CLIENT "client"
# define USAGE_CLIENT "usage: ./client server_PID string_that_should_be_sent\n"
# define ERR_INVAL_PID_SERVER "Invalid server PID\n"
# define ERR_PENDING_RESP "Pending response from server...\n"
# define ERR_FAILED_SIGNAL "Failed to send signal\n"
# define ERR_FAILED_GET_ACK "Failed to get ACK from server\n"
# define ERR_FAILED_FIND_SESS "Failed to find session\n"
# define ERR_SIGACTION "Failed to sigaction()\n"
# define ERR_SIGNAL "Failed to signal()\n"
# define ERR_MALLOC "Failed to malloc()\n"
# define INFO_SENT_SYN1_SERVER "Sent SYN1 to server\n"
# define INFO_RECV_ACK1_SERVER "Received ACK1 from server\n"
# define INFO_CONN_ESTAB "Connection established\n"
# define INFO_CONN_CLOSED "Connection closed\n"
# define INFO_SERVER_GOOD_COPY_STR "Server says 'good copy that string'\n"

/*
**	Define macros in need.
*/

# define TRUE 1
# define FALSE 0
# define THRESHOLD_SEC 4
# define MAX_RETRY 2
# define GAP_MICROSEC 250

/*
**	Define struct list node.
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**	ft_lst*_bonus.c
*/

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

/*
**	Define struct session.
*/

typedef struct s_session
{
	pid_t			pid;
	int				status;
	char			*msg;
	char			buf;
}					t_session;

/*
**	Define status macro of struct session.
*/

# define SESS_STATUS_RECV 0
# define SESS_STATUS_WAIT 1

/*
**	ft_init_session_bonus.c
*/

int					ft_init_session(t_list **sessions, pid_t pid);

/*
**	ft_free_session_bonus.c
*/

void				ft_free_session(void *session);

/*
**	ft_lstfind_session_pid_bonus.c
*/

t_list				*ft_lstfind_session_pid(t_list *s, pid_t pid);

/*
**	ft_lstdelone_session_pid_bonus.c
*/

void				ft_lstdelone_session_pid(t_list **sessions, pid_t pid);

/*
**	ft_append_buf_to_msg_session_bonus.c
*/

int					ft_append_buf_to_msg_session(t_session *session);

/*
**	ft_toggle_session_in_server_bonus.c
*/

void				ft_toggle_session_in_server(pid_t pid_server,
						char *done_msg);

/*
**	ft_put_client_msg_bonus.c
*/

void				ft_put_client_msg(pid_t pid, char *msg);

/*
**	ft_strlen_bonus.c
*/

int					ft_strlen(char *s);

/*
**	ft_strlcpy_bonus.c
*/

size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);

/*
**	ft_strdup_bonus.c
*/

char				*ft_strdup(char *str);

/*
**	ft_strjoin_bonus.c
*/

char				*ft_strjoin(char *s1, char *s2);

/*
**	ft_character_bonus.c
*/

int					ft_isdigit(char c);
int					ft_issign(char c);
int					ft_isspace(char c);

/*
**	ft_check_if_str_is_int_bonus.c
*/

int					ft_check_if_str_is_int(char *s);

/*
**	ft_atoi_bonus.c
*/

int					ft_atoi(const char *nptr);

/*
**	ft_error_bonus.c
*/

void				ft_print_error(char *prefix, char *msg);
void				ft_exit_with_error_msg(char *prefix, char *msg);

/*
**	ft_putchar_fd_bonus.c
*/

void				ft_putchar_fd(char c, int fd);

/*
**	ft_putstr_fd_bonus.c
*/

void				ft_putstr_fd(char *s, int fd);

/*
**	ft_putnbr_fd_bonus.c
*/

void				ft_putnbr_fd(int n, int fd);

#endif
