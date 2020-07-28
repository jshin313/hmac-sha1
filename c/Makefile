CC = gcc

binary = hmac

hmac:
	$(CC) -o hmac hmac.c teeny-sha1.c

.PHONY : clean
clean :
	-rm $(binary)
