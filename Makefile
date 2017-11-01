minimal: minimal.o
	g++ -std=c++11 -o minimal minimal.cpp -lsfml-window -lsfml-system -lsfml-graphics

minimal.o: minimal.cpp
	g++ -c minimal.cpp

GameRunner: Game.o GameRunner.o
	g++ -std=c++11 Game.o GameRunner.o -o game -lsfml-graphics -lsfml-window -lsfml-system

Game.o: Game.cpp Game.hpp
	g++ -c -std=c++11 Game.cpp

GameRunner.o: GameRunner.cpp
	g++ -c -std=c++11 GameRunner.cpp

clean:
	rm -f *.o *~ minimal game
