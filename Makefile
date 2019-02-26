#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 05:58:45 by gmelisan          #+#    #+#              #
#    Updated: 2019/02/26 06:54:12 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell

LIBFT = ./libft

CC = @clang
CFLAGS = -Wall -Wextra -g

OBJ = $(addprefix ./src/, \
main.o error.o main_loop.o tokenize.o exec_line.o get_command.o)

all: $(NAME)

$(NAME): $(LIBFT)/libft.a $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT) -lft
	@echo "\033[0;32mFile $@ was successfully created.\033[0m"

$(OBJ): ./include/minishell.h

%.o: %.c
	$(CC) $(CFLAGS) -I./include -I$(LIBFT)/include -c -o $@ $<
	@echo "\033[1;34mCompiling ($(CFLAGS)) \033[0;36m$<\033[0m"

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)/libft.a

re: fclean all

