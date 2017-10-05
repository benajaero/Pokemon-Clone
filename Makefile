game:
	g++ -g --std=c++11 game.cpp -framework sfml-graphics -framework sfml-window -framework sfml-system -o game.o -Wall -Werror
mac:
	g++ -g --std=c++11 main.cpp -framework sfml-graphics -framework sfml-window -framework sfml-system -o main.o -Wall -Werror

all:
	g++ -g --std=c++11 *.cpp -framework sfml-graphics -framework sfml-window -framework sfml-system -o main.o -Wall -Werror
clean:
	rm *.o
