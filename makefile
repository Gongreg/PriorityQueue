.PHONY: build
build: main.out

.PHONY: build_debug
build_debug: debug.out

debug.out: debug.o queue.o queue_write.o queue_codes.o
	gcc debug.o queue.o queue_write.o queue_codes.o -o debug.out

debug.o: debug.c queue.h queue_data.h queue_write.h
	gcc -c debug.c

main.out: main.o queue.o queue_codes.o
	gcc main.o queue.o queue_codes.o -o main.out

main.o: main.c queue.h queue_data.h
	gcc -c main.c

queue_codes.o: queue_codes.c queue_codes.h
	gcc -c queue_codes.c

queue.o: queue.c queue.h queue_data.h queue_codes.h
	gcc -c queue.c

queue_write.o: queue_write.c queue_codes.o queue.o
	gcc -c queue_write.c
