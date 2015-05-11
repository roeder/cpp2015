Student.o : Student.cpp Student.hpp
	g++ -Wall -c -O Student.cpp

GraduateStudent.o : GraduateStudent.cpp GraduateStudent.hpp
	g++ -Wall -c -O GraduateStudent.cpp

PhdStudent.o : PhdStudent.cpp PhdStudent.hpp
	g++ -Wall -c -O PhdStudent.cpp

MyStudents.o : MyStudents.cpp Student.hpp GraduateStudent.hpp PhdStudent.hpp
	g++ -Wall -c -O MyStudents.cpp

run : Student.o GraduateStudent.o PhdStudent.o MyStudents.o
	g++ -Wall -O -o run Student.o GraduateStudent.o PhdStudent.o MyStudents.o
