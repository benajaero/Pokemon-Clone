mac:
	g++ -g --std=c++11 main.cpp -framework sfml-graphics -framework sfml-window -framework sfml-system -o main.o
clean:
	rm *.o
