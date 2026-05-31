CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
LDLIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

all: testLine, koch, fractaltree, levy

testLine: turtlec.c examples/testLine.c turtlec.h
	$(CC) $(CFLAGS) turtlec.c examples/testLine.c -o testLine $(LDLIBS)

testLine: turtlec.c examples/koch.c turtlec.h
	$(CC) $(CFLAGS) turtlec.c examples/koch.c -o koch $(LDLIBS)

testLine: turtlec.c examples/fractaltree.c turtlec.h
	$(CC) $(CFLAGS) turtlec.c examples/fractaltree.c -o fractaltree $(LDLIBS)

testLine: turtlec.c examples/levy.c turtlec.h
	$(CC) $(CFLAGS) turtlec.c examples/levy.c -o levy $(LDLIBS)

clean:
	rm -f testLine, koch, fractaltree, levy

