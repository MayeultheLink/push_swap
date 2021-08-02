# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 15:02:27 by mde-la-s          #+#    #+#              #
#    Updated: 2021/08/02 18:38:44 by mde-la-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
			libft/ft_strlen.c \
			libft/ft_isdigit.c \
			libft/ft_lstnew.c \
			libft/ft_lstadd_back.c \
			libft/ft_lstadd_front.c \
			libft/ft_lstlast.c \
			libft/ft_atoi.c \
			libft/ft_lstsize.c \
			main.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

push_swap	:	${OBJS}
		${CC} ${CFLAGS} ${SRCS}

clean		:
	rm ${OBJS} a.out
