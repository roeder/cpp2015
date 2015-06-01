Vector.o : Vector.cpp Vector.hpp
	g++ -Wall -c -O Vector.cpp

Matrix.o : Matrix.cpp Matrix.hpp
	g++ -Wall -c -O Matrix.cpp

LinearSystem.o : LinearSystem.cpp LinearSystem.hpp
	g++ -Wall -c -O LinearSystem.cpp

PosDefSymmLinearSystem.o : PosDefSymmLinearSystem.cpp PosDefSymmLinearSystem.hpp
	g++ -Wall -c -O PosDefSymmLinearSystem.cpp

TestLS.o : TestLS.cpp Vector.hpp Matrix.hpp LinearSystem.hpp PosDefSymmLinearSystem.hpp
	g++ -Wall -c -O TestLS.cpp

run : Vector.o TestLS.o Matrix.o LinearSystem.o PosDefSymmLinearSystem.o
	g++ -Wall -O -o run Vector.o Matrix.o LinearSystem.o PosDefSymmLinearSystem.o TestLS.o
