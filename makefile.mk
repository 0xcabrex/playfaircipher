mainfile:client.o server.o
	gcc client.o server.o -o mainfile

client.o:client.c header.h
	gcc -c client.c

server.o:modules/server.c header.h
	gcc -c modules/server.c
