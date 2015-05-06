ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	g++ -Wall -c -O ComplexNumber.cpp

MyComplexNumber.o : MyComplexNumber.cpp ComplexNumber.hpp
	g++ -Wall -c -O MyComplexNumber.cpp

run : ComplexNumber.o MyComplexNumber.o
	g++ -Wall -O -o run ComplexNumber.o MyComplexNumber.o
