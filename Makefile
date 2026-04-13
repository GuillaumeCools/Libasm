# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcools <gcools@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/13 14:24:28 by gcools            #+#    #+#              #
#    Updated: 2026/04/13 15:37:07 by gcools           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NASM = nasm
NFLAGS = -f elf64

INCLUDE = -I includes
SRCS_DIR = srcs/
				
C_SRCS = main.c
S_SRCS = ft_strlen.s		

OBJS = $(C_SRCS:.c=.o) $(S_SRCS:.s=.o)

all : $(NAME)

$(NAME) : $(OBJS)

	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "Ready to use !"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(NASM) $(NFLAGS) $< -o $@

clean :
	rm -rf $(OBJS)


fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
