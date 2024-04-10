main: main.o tome.o
	g++ main.o tome.o -o main

tome.o: tome.cpp
	g++ -c tome.cpp

main.o: main.cpp
	g++ -c main.cpp

run: 
	./main

clean:
	rm *.o main
