Matrix2x2.o : Matrix2x2.cpp Matrix2x2.hpp
	g++ -Wall -c -O Matrix2x2.cpp

MyMatrix2x2.o : MyMatrix2x2.cpp Matrix2x2.hpp
	g++ -Wall -c -O MyMatrix2x2.cpp

run : Matrix2x2.o MyMatrix2x2.o
	g++ -Wall -O -o run Matrix2x2.o MyMatrix2x2.o
