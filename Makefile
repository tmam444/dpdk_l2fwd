# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chulee <chulee@nstek.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 14:04:03 by chulee            #+#    #+#              #
#    Updated: 2023/03/23 11:47:21 by chulee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=l2fwd
SRCS=$(wildcard srcs/*.c)
OBJS = $(addprefix objs/, $(notdir $(SRCS:.c=.o)))
CC = cc
CFLAGS = -O3 -I./includes $(shell pkg-config --cflags libdpdk) -DALLOW_EXPERIMENTAL_API
LDFLAGS = $(shell pkg-config --libs libdpdk)
OBJ_FILES = $(OBJS)

$(NAME) : $(OBJ_FILES)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LDFLAGS)

objs/%.o : srcs/%.c
		$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

all : $(NAME)

re : fclean all

.PHONY: clean fclean all re

