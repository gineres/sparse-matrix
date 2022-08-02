main: main.o Matrix.o Tests.o
	g++ -o main main.o Matrix.o Tests.o

Tests.o: Tests.cpp
	g++ -c Tests.cpp

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp

main.o: main.cpp
	g++ -c main.cpp