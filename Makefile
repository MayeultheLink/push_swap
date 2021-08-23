# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 15:02:27 by mde-la-s          #+#    #+#              #
#    Updated: 2021/08/23 17:15:44 by mde-la-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
NAMEBON	=	checker

LIBFT	=	libft/libft.a
SRCS	=	srcs/analyse_params/get_params.c \
			srcs/analyse_params/pos.c \
			srcs/analyse_params/suite.c \
			srcs/cmd/cmd_p.c \
			srcs/cmd/cmd_r.c \
			srcs/cmd/cmd_rr.c \
			srcs/cmd/cmd_s.c \
			srcs/sorting/sorting_5/sorting.c \
			srcs/sorting/sorting_5/sorting_3.c \
			srcs/sorting/sorting_5/sorting_4.c \
			srcs/sorting/sorting_5/sorting_5.c \
			srcs/sorting/sorting_5/sorting_5_no_suite_1.c \
			srcs/sorting/sorting_5/sorting_5_no_suite_2.c \
			srcs/sorting/sorting_5/sorting_5_suite_3.c \
			srcs/sorting/sorting_500/sorting.c \
			srcs/sorting/sorting_500/sorting_200.c \
			srcs/sorting/sorting_500/sorting_500.c \
			push_swap.c
BONUS	=	bonus/analyse_params/get_params.c \
			bonus/analyse_params/suite.c \
			bonus/cmd/cmd_p_bonus.c \
			bonus/cmd/cmd_r_bonus.c \
			bonus/cmd/cmd_rr_bonus.c \
			bonus/cmd/cmd_s_bonus.c \
			bonus/get_next_line.c \
			bonus/checker.c

# Colors
_GREY=$ \x1b[30m
_RED=$ \x1b[31m
_GREEN=$ \x1b[32m
_YELLOW=$ \x1b[33m
_BLUE=$ \x1b[34m
_PURPLE=$ \x1b[35m
_CYAN=$ \x1b[36m
_WHITE=$ \x1b[37m
_END=$ \x1b[0m

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -I./headers

OBJS	=	${SRCS:.c=.o}
OBJSBON	=	${BONUS:.c=.o}

all		:	${NAME}

$(NAME)	:	${OBJS} ${OBJSBON}
		${MAKE} -C ./libft
		${MAKE} bonus -C ./libft
		@echo "$(_GREEN)LIBFT OK${_END}"
		${CC} ${CFLAGS} -o $(NAME) ${OBJS} ${LIBFT}
		@echo "$(_GREEN)MANDATORY OK${_END}"
		${CC} ${CFLAGS} -o $(NAMEBON) ${OBJSBON} ${LIBFT}
		@echo "$(_GREEN)BONUS OK${_END}"

clean	:
		${MAKE} clean -C libft
		rm -f ${OBJS} ${OBJSBON}

fclean	:	clean
		rm -f ${NAME} ${NAMEBON}

re		:	fclean all

.PHONY	:	all clean fclean re
