Game: Aircraft.o Entity.o Game.o GameRunner.o SceneNode.o SpriteNode.o World.o
	g++ -std=c++11 Aircraft.o Entity.o Game.o GameRunner.o SceneNode.o SpriteNode.o World.o -lsfml-graphics -lsfml-window -lsfml-system -o game

Aircraft.o: Aircraft.h Aircraft.cpp
	g++ -c -std=c++11 Aircraft.cpp

Entity.o: Entity.h Entity.cpp
	g++ -c -std=c++11 Entity.cpp

Game.o: Game.cpp Game.h
	g++ -c -std=c++11 Game.cpp

GameRunner.o: GameRunner.cpp
	g++ -c -std=c++11 GameRunner.cpp

SceneNode.o: SceneNode.h SceneNode.cpp
	g++ -c -std=c++11 SceneNode.cpp

SpriteNode.o: SpriteNode.h SpriteNode.cpp
	g++ -c -std=c++11 SpriteNode.cpp

World.o: World.h World.cpp
	g++ -c -std=c++11 World.cpp

Clean:
	rm -rf *.o *~ game
