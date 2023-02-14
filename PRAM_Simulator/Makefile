all: finalBuild

finalBuild: main.o simulator.o pramhelper.o
	g++-12 main.o simulator.o pramhelper.o -o finalBuild

main.o: main.cpp
	g++-12 main.cpp -c

simulator.o: simulator.cpp
	g++-12 simulator.cpp -c

pramhelper.o: pramhelper.cpp
	g++-12 pramhelper.cpp -c

clean:
	rm -f *.o