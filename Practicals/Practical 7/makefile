main: main.o train.o bin.o 
	g++ -o main main.o train.o bin.o 

main.o: main.cpp train.o bin.o 
	g++ -c main.cpp

train.o: train.h train.cpp
	g++ -c train.cpp

bin.o: bin.h bin.cpp
	g++ -c bin.cpp

run: 
	./main

clean:
	rm *.o main