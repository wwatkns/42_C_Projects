FLAG= -Wall -Werror -Wextra
CC= gcc

all:
	$(CC) $(FLAG) -o Colleen Colleen.c
	$(CC) $(FLAG) -o Grace Grace.c
	$(CC) $(FLAG) -o Sully Sully.c

clean:
	rm -f Grace_kid.c

fclean: clean
	rm -f Sully
	rm -f Grace
	rm -f Colleen

re: fclean all

.PHONY: clean fclean re all
