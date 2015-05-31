Vector.o : Vector.cpp Vector.hpp
	g++ -Wall -c -O Vector.cpp

TestLS.o : TestLS.cpp Vector.hpp
	g++ -Wall -c -O TestLS.cpp

run : Vector.o TestLS.o
	g++ -Wall -O -o run Vector.o TestLS.o
