Lab9: main.o Executive.o Pokemon.o TreeTest.o
	g++ -std=c++11 -g -Wall main.o Executive.o Pokemon.o TreeTest.o -o Lab9

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp BST.h Pokemon.h TreeTest.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

TreeTest.o: TreeTest.h TreeTest.cpp BST.h
	g++ -std=c++11 -g -Wall -c TreeTest.cpp

clean:
	rm *.o lab9


