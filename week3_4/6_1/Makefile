ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	g++ -c -O ComplexNumber.cpp

MyComplexNumber.o : MyComplexNumber.cpp ComplexNumber.hpp
	g++ -c -O MyComplexNumber.cpp

run : ComplexNumber.o MyComplexNumber.o
	g++ -O -o run ComplexNumber.o MyComplexNumber.o
