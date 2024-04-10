main: main.o fireControl.o weapon.o laser.o missile.o
	g++ -o main main.o fireControl.o weapon.o laser.o missile.o

main.o: main.cpp fireControl.o weapon.o laser.o missile.o
	g++ -c main.cpp

fireControl.o: fireControl.h fireControl.cpp
	g++ -c fireControl.cpp

weapon.o: weapon.h weapon.cpp
	g++ -c weapon.cpp

laser.o: laser.h laser.cpp
	g++ -c laser.cpp

missile.o: missile.h missile.cpp
	g++ -c missile.cpp

run: 
	./main

clean:
	rm *.o main