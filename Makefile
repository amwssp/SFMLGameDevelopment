minimal: minimal.o
	g++ -std=c++11 -o minimal minimal.cpp -lsfml-window -lsfml-system -lsfml-graphics

minimal.o: minimal.cpp
	g++ -c minimal.cpp
