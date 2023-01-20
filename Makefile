# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcatwoma <wcatwoma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 18:47:23 by wcatwoma          #+#    #+#              #
#    Updated: 2021/07/02 18:47:25 by wcatwoma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/minishell.c \
		./srcs/other.c \
		./srcs/other2.c \
		./srcs/other3.c \
		./srcs/edit_env.c \
		./srcs/checkers.c \
		./srcs/checker_line.c \
		./srcs/tools_mas1.c \
		./srcs/tools_mas2.c \
		./srcs/sort.c \
		./srcs/replace.c \
		./srcs/errors/error.c \
		./srcs/init.c \
		./srcs/pipe.c \
		./srcs/parse.c \
		./srcs/signal.c \
		./srcs/exit.c \
		./srcs/commands/ft_cd.c \
		./srcs/commands/ft_echo.c \
		./srcs/commands/ft_env.c \
		./srcs/commands/ft_exit.c \
		./srcs/commands/ft_export.c \
		./srcs/commands/ft_other.c \
		./srcs/commands/ft_pwd.c \
		./srcs/commands/ft_unset.c

HEADER = ./header.h
FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

NAME = minishell
LIBFTDIR = ./srcs/libft/
LIBFT = $(LIBFTDIR)libft.a


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(FLAGS) -o $@ $^

$(LIBFT):
	make -C $(LIBFTDIR)

%.o: %.c $(HEADER)
	gcc -I $(HEADER) -c $< -o $@

clean:
	rm -f ./srcs/*/*.o
	rm -f ./srcs/*.o
	rm -f ./srcs/tools/gnl/*.o
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f minishell
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all, clean, fclean, re