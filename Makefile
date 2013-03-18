clean:
	rm exterminate

compile:
	g++ -Wall `sdl-config --cflags` `sdl-config --libs` -o exterminate exterminate.cpp lib/*

debian:
	g++ -I /usr/include/SDL/ -Wall -o exterminate exterminate.cpp lib/* -lSDL
