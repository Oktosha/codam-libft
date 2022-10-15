CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c

BONUS_SRCS = ft_lstnew_bonus.c

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
