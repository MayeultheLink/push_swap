# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 15:02:27 by mde-la-s          #+#    #+#              #
#    Updated: 2021/08/12 15:46:25 by mde-la-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	checker

LIBFT	:=	libft/*.c

LIBDIR	:=	./libft

SRCS	:=	analyse_params/get_params.c \
			analyse_params/suite.c \
			cmd/cmd_p_bonus.c \
			cmd/cmd_r_bonus.c \
			cmd/cmd_rr_bonus.c \
			cmd/cmd_s_bonus.c \
			get_next_line.c \
			checker.c

OBJS	:=	${SRCS:.c=.o}

CC		?=	clang

CFLAGS	?=	-Wall -Wextra -Werror -fsanitize=address

all		:	${NAME}

$(NAME)	:	${OBJS}
		@cd ${LIBDIR} && ${MAKE}
		${CC} ${CFLAGS} ${SRCS} ${LIBFT}
		mv a.out checker

clean	:	
		@cd ${LIBDIR} && ${MAKE} clean
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
