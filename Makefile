CC=gcc
CFLAGS=
LDFLAGS=
EXEC=test

all: $(EXEC)

$(EXEC): main.o graph.o list.o stack.o queue.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: graph.o list.o stack.o queue.o

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)