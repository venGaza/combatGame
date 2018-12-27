$(CXX) = g++
CFLAGS = -std=c++0x

output: main.o Game.o Queue.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o getInteger.o randomNumber.o
	g++ main.o Game.o Queue.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o getInteger.o randomNumber.o -o FantasyCombatGame

main.o: main.cpp
	g++ -c  -std=c++0x main.cpp	

Game.o: Game.cpp
	g++ -c  -std=c++0x Game.cpp

Queue.o: Queue.cpp
	g++ -c  -std=c++0x Queue.cpp

Character.o: Character.cpp
	g++ -c  -std=c++0x Character.cpp

Barbarian.o: Barbarian.cpp
	g++ -c  -std=c++0x Barbarian.cpp

Vampire.o: Vampire.cpp
	g++ -c  -std=c++0x Vampire.cpp

BlueMen.o: BlueMen.cpp
	g++ -c  -std=c++0x BlueMen.cpp

Medusa.o: Medusa.cpp
	g++ -c  -std=c++0x Medusa.cpp

HarryPotter.o: HarryPotter.cpp
	g++ -c  -std=c++0x HarryPotter.cpp

getInteger.o: getInteger.cpp
	g++ -c -std=c++0x getInteger.cpp

randomNumber.o: randomNumber.cpp
	g++ -c -std=c++0x randomNumber.cpp

clean:
	rm *.o FantasyCombatGame