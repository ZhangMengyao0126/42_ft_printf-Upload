# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhang <mzhang@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 10:02:04 by mzhang            #+#    #+#              #
#    Updated: 2024/08/23 14:18:28 by mzhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_print_character.c ft_print_digit.c ft_print_pointer.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
