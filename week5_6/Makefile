Vector.o : Vector.cpp Vector.hpp
	g++ -Wall -c -O Vector.cpp

Matrix.o : Matrix.cpp Matrix.hpp
	g++ -Wall -c -O Matrix.cpp

TestLS.o : TestLS.cpp Vector.hpp Matrix.hpp
	g++ -Wall -c -O TestLS.cpp

run : Vector.o TestLS.o
	g++ -Wall -v -O -o run Vector.o Matrix.o TestLS.o
