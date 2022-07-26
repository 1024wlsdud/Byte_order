all: Byte_order

Byte_order: main.o
	g++ -o Byte_order main.o

main.o: main.cpp

clean:
	rm -f Byte_order
	rm -f *.o
