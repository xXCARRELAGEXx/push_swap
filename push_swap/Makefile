# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrault <rrault@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 16:07:00 by rrault            #+#    #+#              #
#    Updated: 2023/08/04 16:15:34 by rrault           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_split.c \
		push_swap.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		check_errors.c \
		check.c \
		ft_strtol.c \
		sort_3.c \
		sort_5.c \
		sort_number.c \
		utils.c \
		valid_args.c \

OBJ = ${SRC:.c=.o}

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

${NAME}: ${OBJ}
	$(CC) $(CFLAGS) -o $@ $^
	
%.o: %.c
		$(CC) $(CFLAGS) -c $<

all: ${NAME}

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
