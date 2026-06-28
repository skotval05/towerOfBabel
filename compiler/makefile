CC = gcc
LEXER_SRC = lexer.c lexer.h
LEXER_TESTS_SRC = lexertests.c lexer.h
CFLAGS = -I.

lexer: lexer.o
	$(CC) -o lexer lexer.o

lexer.o: lexer.c
	$(CC) $(CFLAGS) -c $(LEXER_SRC)

lexertests: lexertests.o lexer.o
	$(CC) -o lexertests lexertests.o lexer.o

lexertests.o: lexertests.c lexer.h
	$(CC) $(CFLAGS) -c lexertests.c

clean:
	rm -f *.o lexer lexertests
