SecondOrderOde.o : SecondOrderOde.cpp SecondOrderOde.hpp
	g++ -Wall -c -O SecondOrderOde.cpp

BoundaryConditions.o : BoundaryConditions.cpp BoundaryConditions.hpp
	g++ -Wall -c -O BoundaryConditions.cpp

FiniteDifferenceGrid.o : FiniteDifferenceGrid.cpp FiniteDifferenceGrid.hpp Node.hpp
	g++ -Wall -c -O FiniteDifferenceGrid.cpp

Vector.o : Vector.cpp Vector.hpp
	g++ -Wall -c -O Vector.cpp

Matrix.o : Matrix.cpp Matrix.hpp
	g++ -Wall -c -O Matrix.cpp

LinearSystem.o : LinearSystem.cpp LinearSystem.hpp
	g++ -Wall -c -O LinearSystem.cpp

BvpOde.o : BvpOde.cpp BvpOde.hpp Vector.o Matrix.o LinearSystem.o FiniteDifferenceGrid.o BoundaryConditions.o SecondOrderOde.o
	g++ -Wall -c -O BvpOde.cpp

TestOde.o : TestOde.cpp BvpOde.o
	g++ -Wall -c -O TestOde.cpp

run : TestOde.o
	g++ -Wall -O -o run SecondOrderOde.o BoundaryConditions.o FiniteDifferenceGrid.o Vector.o Matrix.o LinearSystem.o BvpOde.o TestOde.o
