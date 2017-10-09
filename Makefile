CFLAGS=-Wall -O3
FILES=project3.h nodeX.h nodeX.c project3.c node0.c node1.c node2.c node3.c README.txt Makefile NodeConfigurationFile

all: dvrp

dvrp: node0.o node1.o node2.o node3.o nodeX.o project3.o
	gcc ${CFLAGS} -o dvrp node0.o node1.o node2.o node3.o nodeX.o project3.o

project3.o: project3.c project3.h
nodeX.o: nodeX.c nodeX.h project3.h
node0: node0.c nodeX.h
node1: node1.c nodeX.h
node2: node2.c nodeX.h
node3: node3.c nodeX.h

clean:
	rm -f *.o crmyers_project3.tar.gz

crmyers_project3.tar.gz: ${FILES}
	tar -cvzf crmyers_project3.tar.gz ${FILES}
