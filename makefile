.PHONY: build
build: main.out

.PHONY: build_debug
build_debug: main_debug.out

main_debug.out: main_debug.o queue.o queue_write.o queue_codes.o
	gcc main_debug.o queue.o queue_write.o queue_codes.o -o main_debug.out

main.out: main.o queue.o queue_codes.o
	gcc main.o queue.o queue_codes.o -o main.out

queue_codes.o: queue_codes.c queue_codes.h
	gcc -c queue_codes.c

queue.o: queue.c queue.h queue_codes.h
	gcc -c queue.c

queue_write.o: queue_write.c queue_codes.o queue.o
	gcc -c queue_write.c

main.o: main.c queue.h
	gcc -c main.c
