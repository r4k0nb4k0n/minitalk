# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyechoi <hyechoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 17:51:42 by hyechoi           #+#    #+#              #
#    Updated: 2021/07/08 00:56:27 by hyechoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME_CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src
SRC_FILE_SERVER = ft_strlen.c\
					ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c\
					server.c
SRC_FILE_CLIENT = client.c
SRCS_SERVER = $(addprefix $(SRC_DIR)/, $(SRC_FILE_SERVER))
SRCS_CLIENT = $(addprefix $(SRC_DIR)/, $(SRC_FILE_CLIENT))
OBJ_DIR = ./obj
OBJ_FILE_SERVER = $(SRC_FILE_SERVER:.c=.o)
OBJ_FILE_CLIENT = $(SRC_FILE_CLIENT:.c=.o)
OBJS_SERVER = $(addprefix $(OBJ_DIR)/, $(OBJ_FILE_SERVER))
OBJS_CLIENT = $(addprefix $(OBJ_DIR)/, $(OBJ_FILE_CLIENT))
INC_DIR = ./includes
INC_FILE = minitalk.h
INCS = $(addprefix $(INC_DIR)/, $(INC_FILE))
INC = -I$(INC_DIR)

all: welcome $(NAME) $(NAME_CLIENT)

$(NAME): $(OBJ_DIR) $(OBJS_SERVER)
	@echo "\n\033[1;37;44m___Generate $@.___\033[0m\n"
	$(CC) $(CFLAGS) -o $@ $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJ_DIR) $(OBJS_CLIENT)
	@echo "\n\033[1;37;44m___Generate $@.___\033[0m\n"
	$(CC) $(CFLAGS) -o $@ $(OBJS_CLIENT)

$(OBJ_DIR):
	@echo "\n\033[1;37;42m___Generate $@.___\033[0m\n"
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean: welcome
	@echo "\n\033[1;37;41m___Clean object files.___\033[0m\n"
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\n\033[1;37;41m___Clean all generated files.___\033[0m\n"
	rm -rf $(NAME) $(NAME_CLIENT)

re: fclean all

welcome:
	@echo "\n\033[1;37;45m# ******************* #\033[0m"
	@echo "\033[1;37;45m# minitalk by hyechoi #\033[0m"
	@echo "\033[1;37;45m# ******************* #\033[0m\n"

# Phony target that is not really name of file;
# rather it is just a name of recipe.
.PHONY: all clean fclean re welcome
