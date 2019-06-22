bugMain: main.o bugWorld.o ant.o doodlebug.o location.o menu.o critter.o
	g++ -std=c++11 main.o bugWorld.o ant.o doodlebug.o location.o critter.o menu.o -o bugMain

main.o: main.cpp
	g++ -std=c++11 main.cpp -c

bugWorld.o: bugWorld.cpp bugWorld.hpp
	g++ bugWorld.cpp -c
	
ant.o: ant.cpp ant.hpp
	g++ ant.cpp -c

critter.o: critter.cpp critter.hpp
	g++ critter.cpp -c

doodlebug.o: doodlebug.cpp doodlebug.hpp
	g++ doodlebug.cpp -c

location.o: location.cpp location.hpp
	g++ location.cpp -c
	
menu.o: menu.cpp menu.hpp
	g++ menu.cpp -c

clean:
	rm *.o bugMain
