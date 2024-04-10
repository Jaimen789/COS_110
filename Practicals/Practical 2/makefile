main: main.o team.o creature.o
	g++ main.o team.o creature.o -o main

main.o: main.cpp
	g++ -c main.cpp

team.o: team.cpp
	g++ -c team.cpp

creature.o: creature.cpp
	g++ -static -c creature.cpp

run: 
	./main

clean:
	rm *.o main
