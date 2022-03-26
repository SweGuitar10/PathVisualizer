all: compile link

compile:
	g++ -I src/include -c main.cpp
link:
	g++ main.o -o main -Lsrc/lib -l sfml-graphics -l sfml-window -l sfml-system