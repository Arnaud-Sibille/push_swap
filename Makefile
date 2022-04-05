# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asibille <asibille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 15:55:24 by asibille          #+#    #+#              #
#    Updated: 2022/03/28 08:12:39 by asibille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = mispl.c go_to_best.c go_to_best_sw.c go_to_focus.c fill.c rot_and_rev.c push.c swap.c struct_ops3.c stack_ops2.c struct_ops.c go_to_best_ad.c go_to_best_pu.c apply_lst.c ft_init_data.c input_to_stack.c ls_ops.c ls_ops2.c res.c stack_ops.c struct_ops2.c utils.c is_ordered.c

MAIN = push_swap.c 

SRCSB = bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c bonus/utils_bonus.c

MAINB = bonus/checker_bonus.c

OBJS = ${SRCS:.c=.o}

MAINOBJ = ${MAIN:.c=.o}

OBJSB = ${SRCSB:.c=.o}

MAINBOBJ = ${MAINB:.c=.o}

NAME = push_swap

NAMEB = checker

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS} ${MAINOBJ}
	make -C libft
	gcc ${CFLAGS} ${OBJS} ${MAINOBJ} libft/libft.a -o ${NAME}
	
all: ${NAME}

bonus : ${OBJS} ${OBJSB} ${MAINBOBJ}
	make -C libft
	gcc ${CFLAGS} ${OBJS} ${OBJSB} ${MAINBOBJ} libft/libft.a -o ${NAMEB}

clean:
	make clean -C libft
	rm -rf ${OBJS} ${MAINOBJ}
	rm -rf ${OBJSB} ${MAINBOBJ}

fclean: clean
	make fclean -C libft
	rm -rf ${NAME}
	rm -rf ${NAMEB}

re: fclean all

.PHONY: all bonus clean fclean re