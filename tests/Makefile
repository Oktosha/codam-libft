test: lib
	$(CC) main.c -I../task -L../task -lft -o test

lib:
	$(MAKE) -C ../task

test-bonus: lib-bonus
	$(CC) bonus.c -I../task -L../task -lft -o test-bonus

lib-bonus:
	$(MAKE) -C ../task bonus

clean:
	rm -f test test-bonus
