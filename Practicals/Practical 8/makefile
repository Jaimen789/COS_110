main: main.o item.o LL.o 
	g++ -o main main.o item.o LL.o 

main.o: main.cpp item.o LL.o 
	g++ -c main.cpp

item.o: item.h item.cpp
	g++ -c item.cpp

LL.o: LL.h LL.cpp
	g++ -c LL.cpp

run: 
	./main

clean:
	rm *.o main