clean:
	rm exterminate

compile:
	g++ -Wall `sdl-config --cflags` `sdl-config --libs` -lSDL_ttf -o exterminate exterminate.cpp lib/*
