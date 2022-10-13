LIBFT_FOLDER = ../task
CFLAGS = -Wall -Wextra -Werror

test: lib
	$(CC) $(CFLAGS) main.c -I$(LIBFT_FOLDER) -L$(LIBFT_FOLDER) -lft -o test

lib:
	$(MAKE) -C $(LIBFT_FOLDER)

test-bonus: lib-bonus
	$(CC) $(CFLAGS) bonus.c -I$(LIBFT_FOLDER) -L$(LIBFT_FOLDER) -lft -o test-bonus

lib-bonus:
	$(MAKE) -C $(LIBFT_FOLDER) bonus

clean:
	rm -f test test-bonus
