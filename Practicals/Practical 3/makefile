main: main.o cauldron.o ingredient.o
	g++ main.o cauldron.o ingredient.o -o main

main.o: main.cpp
	g++ -c main.cpp

team.o: cauldroneam.cpp
	g++ -c cauldron.cpp

ingredient.o: ingredient.cpp
	g++ -static -c ingredient.cpp

run: 
	./main

clean:
	rm *.o main
