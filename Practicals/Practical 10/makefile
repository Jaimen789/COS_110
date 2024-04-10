main: main.o heatStack.o heatNode.o msgQueue.o msgNode.o
	g++ main.o heatStack.o heatNode.o msgQueue.o msgNode.o -o main

heatStack.o: heatStack.cpp
	g++ -c heatStack.cpp

heatNode.o: heatNode.cpp
	g++ -c heatNode.cpp

msgQueue.o: msgQueue.cpp
	g++ -c msgQueue.cpp

msgNode.o: msgNode.cpp
	g++ -c msgNode.cpp

main.o: main.cpp 
	g++ -c main.cpp

run: 
	./main

clean:
	rm *.o main