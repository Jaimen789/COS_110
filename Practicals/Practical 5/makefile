main: main.o vehicle.o locomotive.o dieselLocomotive.o electricLocomotive.o
	g++ -o main main.o vehicle.o locomotive.o dieselLocomotive.o electricLocomotive.o

main.o: main.cpp vehicle.o locomotive.o dieselLocomotive.o electricLocomotive.o
	g++ -c main.cpp

vehicle.o: vehicle.h vehicle.cpp
	g++ -c vehicle.cpp

locomotive.o: locomotive.h locomotive.cpp
	g++ -c locomotive.cpp

dieselLocomotive.o: dieselLocomotive.h dieselLocomotive.cpp
	g++ -c dieselLocomotive.cpp

electricLocomotive.o: electricLocomotive.h electricLocomotive.cpp
	g++ -c electricLocomotive.cpp

run: 
	./main

clean:
	rm *.o main
