main: main.o item.o rLL.o
	g++ main.o item.o rLL.o -o main

item.o: item.cpp
	g++ -c item.cpp

rLL.o: rLL.cpp
	g++ -c rLL.cpp

main.o: main.cpp 
	g++ -c main.cpp

run: 
	./main

clean:
	rm *.o main