# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/22 12:56:05 by kmfoloe           #+#    #+#              #
#    Updated: 2018/09/27 09:02:59 by kmfoloe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
GCC=gcc
INCLUDES= -I ./includes -I ./libft/includes/
LIBFT= libft/libft.a
SRCS= ./srcs/main.c\
	./srcs/environment.c\
	./srcs/ft_env.c\
	./srcs/ft_setenv.c\
	./srcs/ft_unsetenv.c\
	./srcs/ft_cd.c\
	./srcs/ft_echo.c\
	./srcs/error_handle.c\
	./srcs/ft_exec.c\
	./srcs/ft_env_helper.c\
	./srcs/signal_handler.c\
	./srcs/count_args.c\
	./srcs/arg_len.c\


FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	@$(GCC) $(SRCS) $(INCLUDES) $(LIBFT) -o $(NAME) $(FLAGS)
	@echo "minishell has been built."

clean:
	@make -C libft fclean

fclean: clean
	@ rm -f $(NAME)
	@echo "minishell has been removed."

re: fclean all

.PHONY: all, clean, fclean, re

