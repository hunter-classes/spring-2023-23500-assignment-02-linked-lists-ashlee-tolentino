OBJECTS = OList.o main.o Node.o
CXXFLAGS = -g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

tests: tests.o
	g++ -o tests tests.o

OList.o: OList.cpp Node.h OList.h

main.o: main.cpp OList.h Node.h

Node.o: Node.cpp Node.h

tests.o: tests.cpp doctest.h
	g++ -c -std=c++11 -Wall tests.cpp


clean:
	rm -f $(OBJECTS)