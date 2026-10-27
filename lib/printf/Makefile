NAME = libftprintf.a

SRCS = ft_adress.c\
		ft_hexputnbr.c\
		ft_printf.c\
		ft_putchar.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_putunnbr.c\
					
OBJS =          ${SRCS:.c=.o}

UNAME_S := $(shell uname -s)

CFLAGS =        -Wall -Wextra -Werror

ifeq ($(UNAME_S), Linux)
    LINUXFLAGS = -lbsd
endif

all:            ${NAME}

${NAME}:        ${OBJS}
				ar rc ${NAME} ${OBJS} ${LINUXFLAGS}

${OBJS_BONUS}:
				cc ${CFLAGS} -c -I.

${OBJS}:
				cc ${CFLAGS} ${SRCS} -c -I.

clean:
				rm -rf ${OBJS}

fclean:         clean
				rm -rf ${NAME}

re:             fclean all

.PHONY:         all clean fclean re