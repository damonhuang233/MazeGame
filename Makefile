escape: escape.cpp mazelocation.o wall.o openspace.o mazelevel.o mazeperson.o intrepidstudent.o ta.o instructor.o maze.o
	g++  escape.cpp mazelocation.o wall.o openspace.o mazelevel.o mazeperson.o intrepidstudent.o ta.o instructor.o maze.o -o escape
mazelocation.o: mazelocation.hpp mazelocation.cpp
	g++  mazelocation.cpp -c -o mazelocation.o
wall.o: wall.hpp wall.cpp
	g++  wall.cpp -c -o wall.o
openspace.o: openspace.hpp openspace.cpp
	g++  openspace.cpp -c -o openspace.o
mazelevel.o: mazelevel.hpp mazelevel.cpp
	g++  mazelevel.cpp -c -o mazelevel.o
mazeperson.o: mazeperson.hpp mazeperson.cpp
	g++  mazeperson.cpp -c -o mazeperson.o
intrepidstudent.o: intrepidstudent.hpp intrepidstudent.cpp
	g++  intrepidstudent.cpp -c -o intrepidstudent.o
ta.o: ta.hpp ta.cpp
	g++  ta.cpp -c -o ta.o
instructor.o: instructor.hpp instructor.cpp
	g++  instructor.cpp -c -o instructor.o
maze.o: maze.hpp maze.cpp
	g++  maze.cpp -c -o maze.o
clean:
	rm -f escape *.o
