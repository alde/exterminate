clean:
	rm exterminate

compile:
	g++ -Wall `sdl-config --cflags` `sdl-config --libs` -o exterminate exterminate.cpp lib/*
