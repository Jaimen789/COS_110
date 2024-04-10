main: main.o ditem.o dLL.o citem.o cLL.o storage.o
	g++ main.o ditem.o dLL.o citem.o cLL.o storage.o -o main

ditem.o: ditem.cpp
	g++ -c ditem.cpp

dLL.o: dLL.cpp
	g++ -c dLL.cpp

citem.o: citem.cpp
	g++ -c citem.cpp

cLL.o: cLL.cpp
	g++ -c cLL.cpp

storage.o: storage.cpp
	g++ -c storage.cpp

main.o: main.cpp 
	g++ -c main.cpp

run: 
	./main

clean:
	rm *.o main