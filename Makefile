# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nforay <nforay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/19 23:34:54 by nforay            #+#    #+#              #
#    Updated: 2020/08/20 00:08:45 by nforay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a
CC			= nasm
CFLAGS		= -f elf64
SRC_PATH	= srcs/
OBJ_PATH	= objs/

SRCS		= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS		= $(SRCS:.s=.o)

SRC			= $(addprefix $(SRC_PATH), $(SRCS))
OBJ			= $(addprefix $(OBJ_PATH), $(OBJS))

all: $(NAME)

$(NAME):		$(OBJ)
				ar rcs $(NAME) $(OBJ)
				@echo "\033[32;1mRun make test to make tester\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.s
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				$(CC) $(CFLAGS) $< -o $@

clean:
				rm -rf $(OBJ_PATH)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

test:			all
				@clang -fsanitize=address -Wall -Werror -Wextra srcs/test.c $(NAME) -o tester
				@echo "\033[32;1mTester Ready: ./tester\033[0m"

.PHONY: all re clean fclean test
