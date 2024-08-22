# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhang <mzhang@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 10:02:04 by mzhang            #+#    #+#              #
#    Updated: 2024/08/22 10:46:47 by mzhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rcs

SRCS = ft_printf.c ft_print_character.c ft_print_digit.c ft_print_pointer.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
TEST = test

all: $(TEST)

$(TEST): $(NAME) test.o
	$(CC) test.o $(NAME) -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) test.o

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re bonus
