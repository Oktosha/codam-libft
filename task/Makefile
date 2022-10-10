CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c

BONUS_SRCS = ft_lstnew.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

.PHONY: all clean fclean re

all: libft.a

libft.a: ${OBJS}
	ar rc $@ $^

bonus: ${OBJS} ${BONUS_OBJS}
	ar rc libft.a $^

%.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	rm -f libft.a

re: fclean all
