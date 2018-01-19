CC=gcc
CFLAGS =-I ./
CFLAGS += -lm
APPS = test-visit_writer

$(APPS): test-visit_writer.o test-function.o visit_writer.o
	$(CC) -o test-visit_writer test-visit_writer.o test-function.o visit_writer.o $(CFLAGS)

.PHONY: clean

clean:
	rm *.o $(APPS)
