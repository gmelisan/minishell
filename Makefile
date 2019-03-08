#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 05:58:45 by gmelisan          #+#    #+#              #
#    Updated: 2019/03/08 19:31:35 by gmelisan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell

LIBFT = ./libft

CC = @clang
CFLAGS = -Wall -Wextra -Werror -g

OBJ = $(addprefix ./src/, \
main.o print_error.o main_loop.o exec_line.o exec_command_wrapper.o \
exec_builtin.o check_builtin.o get_env.o get_argv.o \
check_command.o env_getval.o env_setval.o env_del.o is_dir.o split_path.o)

OBJ += $(addprefix ./src/builtin/, \
builtin_cd.o builtin_exit.o builtin_pwd.o builtin_env.o builtin_setenv.o \
builtin_unsetenv.o builtin_echo.o builtin_help.o)

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

