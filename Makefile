# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-s <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 15:02:27 by mde-la-s          #+#    #+#              #
#    Updated: 2021/07/29 15:13:22 by mde-la-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	analyse_params/get_params.c \
			analyse_params/pos.c \
			analyse_params/suite.c \
			cmd/cmd_p.c \
			cmd/cmd_r.c \
			cmd/cmd_rr.c \
			cmd/cmd_s.c \
			sorting/quick_sort.c \
			sorting/sort.c \
			sorting/sort_5.c \
			libft/ft_atoi.c \
			libft/ft_isdigit.c \
			libft/ft_lstadd_back.c \
			libft/ft_lstadd_front.c \
			libft/ft_lstdelone.c \
			libft/ft_lstfree.c \
			libft/ft_lstlast.c \
			libft/ft_lstmin.c \
			libft/ft_lstnew.c \
			libft/ft_lstsize.c \
			libft/ft_strlen.c \
			main.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

push_swap	:	${OBJS}
		${CC} ${CFLAGS} ${SRCS}

clean		:
	rm ${OBJS} a.out
