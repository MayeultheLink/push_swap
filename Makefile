# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 15:02:27 by mde-la-s          #+#    #+#              #
#    Updated: 2021/08/14 23:34:49 by mde-la-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIBFT	=	libft/*.c

LIBDIR	=	./libft

SRCS	=	analyse_params/get_params.c \
			analyse_params/pos.c \
			analyse_params/suite.c \
			cmd/cmd_p.c \
			cmd/cmd_r.c \
			cmd/cmd_rr.c \
			cmd/cmd_s.c \
			sorting/sorting_5/sorting.c \
			sorting/sorting_5/sorting_3.c \
			sorting/sorting_5/sorting_4.c \
			sorting/sorting_5/sorting_5.c \
			sorting/sorting_5/sorting_5_no_suite_1.c \
			sorting/sorting_5/sorting_5_no_suite_2.c \
			sorting/sorting_5/sorting_5_suite_3.c \
			sorting/sorting_500/sorting.c \
			sorting/sorting_500/sorting_200.c \
			sorting/sorting_500/sorting_500.c \
			push_swap.c

BONDIR	=	./bonus

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

all		:	${NAME}

$(NAME)	:	${OBJS} 
		@cd ${LIBDIR} && ${MAKE}
		${CC} ${CFLAGS} ${SRCS} ${LIBFT}
		mv a.out push_swap
		@cd ${BONDIR} && ${MAKE}

clean	:	
		@cd ${LIBDIR} && ${MAKE} clean
		@cd ${BONDIR} && ${MAKE} clean
		rm -f ${OBJS}

fclean	:	clean
		rm -f ${NAME} checker

re		:	fclean all

.PHONY	:	all clean fclean re
