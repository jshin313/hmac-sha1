CC = gcc
CFLAGS += -DREGULAR

binary = hmac

hmac:
	$(CC) -o $(binary) hmac.c teeny-sha1.c $(CFLAGS)

.PHONY : clean
clean :
	-rm $(binary)
