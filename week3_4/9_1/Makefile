Exception.o : Exception.cpp Exception.hpp
	g++ -Wall -c -O Exception.cpp

FileNotOpenException.o : FileNotOpenException.cpp FileNotOpenException.hpp
	g++ -Wall -c -O FileNotOpenException.cpp

OutOfRangeException.o : OutOfRangeException.cpp OutOfRangeException.hpp
	g++ -Wall -c -O OutOfRangeException.cpp

TestExceptions.o : TestExceptions.cpp Exception.hpp FileNotOpenException.hpp OutOfRangeException.hpp
	g++ -Wall -c -O TestExceptions.cpp

run : Exception.o FileNotOpenException.o OutOfRangeException.o TestExceptions.o
	g++ -Wall -O -o run Exception.o FileNotOpenException.o OutOfRangeException.o TestExceptions.o
