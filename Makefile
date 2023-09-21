# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmartini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 17:41:17 by fmartini          #+#    #+#              #
#    Updated: 2023/09/20 17:55:48 by fmartini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc -g

SRC = main.c ft_sorting.c push_utils.c ft_push.c ft_swap.c ft_rotate.c ft_check_av.c \
ft_splitfication.c ft_optimizer.c ft_cases_a.c ft_optimizer_utils.c ft_sorting_utils.c \
ft_sorty_utils.c

OBJ_S = $(SRC:.c=.o)

LIBFT = libft/libft.a

CFLAG = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ_S) $(LIBFT)
	@$(CC) $(CFLAG) $(OBJ_S) $(LIBFT) -o $@

$(LIBFT):
	@make -s -C ./libft

.o: %.c	
	@ $(CC) -c $(CFLAG) -I. $< -o $@

clean:
	@ /bin/rm -f *.o
	@make -s -C ./libft clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@make -s -C ./libft fclean

re: fclean all

.PHONY: all bonus clean fclean re

#tdtyf
