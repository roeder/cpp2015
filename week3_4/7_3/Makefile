AbstractOdeSolver.o : AbstractOdeSolver.cpp AbstractOdeSolver.hpp
	g++ -Wall -c -O AbstractOdeSolver.cpp

FowardEulerSolver.o : FowardEulerSolver.cpp FowardEulerSolver.hpp
	g++ -Wall -c -O FowardEulerSolver.cpp

RungeKuttaSolver.o : RungeKuttaSolver.cpp RungeKuttaSolver.hpp
	g++ -Wall -c -O RungeKuttaSolver.cpp

TestSolver.o : TestSolver.cpp AbstractOdeSolver.hpp FowardEulerSolver.hpp RungeKuttaSolver.hpp
	g++ -Wall -c -O TestSolver.cpp

run : AbstractOdeSolver.o FowardEulerSolver.o RungeKuttaSolver.o TestSolver.o
	g++ -Wall -O -o run AbstractOdeSolver.o FowardEulerSolver.o RungeKuttaSolver.o TestSolver.o
