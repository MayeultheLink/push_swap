# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 15:02:27 by mde-la-s          #+#    #+#              #
#    Updated: 2021/08/10 15:51:55 by mde-la-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT	=	libft/ft_strlen.c \
			libft/ft_isdigit.c \
			libft/ft_lstnew.c \
			libft/ft_lstadd_back.c \
			libft/ft_lstadd_front.c \
			libft/ft_lstlast.c \
			libft/ft_atoi.c \
			libft/ft_lstsize.c

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

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBDIR:=./libft

push_swap	:	${OBJS}
		@cd ${LIBDIR} && ${MAKE}
		${CC} ${CFLAGS} ${SRCS} ${LIBFT}
		mv a.out push_swap

clean		:	
		@cd ${LIBDIR} && ${MAKE} clean
		rm ${OBJS} push_swap
