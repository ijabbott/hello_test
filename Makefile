CC = gcc
CFLAGS = -c -Wall
TST_LIBS = -lcheck -lm -lpthread -lrt

check_hello: check_hello.c hello_world.c hello_world.h
	gcc -g check_hello.c hello_world.c -o check `pkg-config --cflags --libs check`
clean: 
	rm -rf *.o
	rm target_bin
