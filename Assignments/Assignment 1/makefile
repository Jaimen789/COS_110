main: main.o matrix.o 
	g++ -o main main.o matrix.o 

main.o: main.cpp matrix.o  
	g++ -c main.cpp

matrix.o: matrix.h matrix.cpp
	g++ -c matrix.cpp

run: 
	./main

clean:
	rm *.o main