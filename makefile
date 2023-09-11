all: main.o conditions.o solver.o
	g++ -o GraphColoring main.o conditions.o solver.o
main.o: main.cpp conditions.h solver.h
	g++ -c main.cpp

conditions.o: conditions.cpp conditions.h
	g++ -c conditions.cpp

solver.o: solver.cpp solver.h
	g++ -c solver.cpp

clean: cleanobj cleanmain 

cleanobj:
	rm -f *.o

cleanmain:
	rm GraphColoring

.PHONY: clean cleanobj cleanmain