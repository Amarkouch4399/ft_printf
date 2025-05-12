# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/06 17:37:50 by ouamarko          #+#    #+#              #
#    Updated: 2025/05/12 21:06:07 by ouamarko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftprintf.a

SRC	= ft_printf.c \


OBJS	= ${SRC:.c=.o}
BOBJECTS = $(BSOURCES:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

AR	= ar rc

all: ${NAME}
	@echo "Done ✅"

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

bonus: ${OBJS} ${BOBJECTS}
	${AR} ${NAME} ${BOBJECTS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} $(BOBJECTS)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re

