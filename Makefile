minimal: minimal.o
	g++ -std=c++11 -o minimal minimal.cpp -lsfml-window -lsfml-system -lsfml-graphics

minimal.o: minimal.cpp
	g++ -c minimal.cpp

GameRunner: Game.cpp GameRunner.cpp
	g++ -c -std=c++11 Game.cpp -o Game.o
	g++ -c -std=c++11 GameRunner.cpp -o GameRunner.o
	g++ -std=c++11 Game.o GameRunner.o -o game -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o *~ minimal game
