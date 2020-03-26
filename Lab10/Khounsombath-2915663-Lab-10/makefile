Lab10: main.o Executive.o Patient.o
	g++ -g -std=c++11 -Wall main.o Executive.o Patient.o -o Lab10

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Heap.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

Patient.o: Patient.h Patient.cpp
	g++ -g -std=c++11 -Wall -c Patient.cpp

clean:
	rm *.o Lab10
