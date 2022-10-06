CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c

OBJS = ${SRCS:.c=.o}

.PHONY: all clean fclean re

all: libft.a

libft.a: ${OBJS}
	ar rc $@ $^

%.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f libft.a

re: fclean all
