# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsatge <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:23:50 by dsatge            #+#    #+#              #
#    Updated: 2024/04/26 12:30:26 by dsatge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

C_FILES_SORT = main.c\
	  rules.c\
	  rules_command.c\
	  sorting.c\
	  utils_sort.c\
	  sorting_command.c\
	  move_to_b.c\
	  move_to_a.c\
	  smart_move.c\
	  extra.c

C_FILES_PARC = create_line.c\
	error_argument.c\
	utils.c\
	list_set_up.c

SORTING = $(addprefix sorting/,${C_FILES_SORT})

PARCING = $(addprefix parcing/,${C_FILES_PARC})

FLAGS = -Wall -Werror -Wextra -I includes/

LIB = libft/libft.a printf/libftprintf.a 
DEPS = $(addprefix lib/,${LIB})

all: ${NAME}

${NAME} : ${SORTING} ${PARCING}
	make -C lib/libft
	make -C lib/printf
	cc ${FLAGS} ${SORTING} ${PARCING} -o ${NAME} ${DEPS}

clean:
	make -C lib/libft clean
	make -C lib/printf clean

fclean:	clean
	rm -rf ${NAME}

re:	fclean all

.PHONY:	all clean fclean re


