ofiles = mainP1.o Game.o Object.o Wall.o Floor.o Map.o Player.o ObjectList.o
gpp_o = g++ -c -g -std=c++98 

main: $(ofiles)
	g++ -std=c++98 $(ofiles) -o main

mainP1.o: mainP1.cpp Game.h 
	$(gpp_o) mainP1.cpp

Game.o: Game.cpp Game.h Map.h Player.h Wall.h Floor.h
	$(gpp_o) Game.cpp

Object.o: Object.cpp Object.h
	$(gpp_o) Object.cpp

Wall.o: Wall.cpp Wall.h Object.h
	$(gpp_o) Wall.cpp

Floor.o: Floor.cpp Floor.h Object.h
	$(gpp_o) Floor.cpp

Map.o: Map.cpp Map.h ObjectList.h
	$(gpp_o) Map.cpp

Player.o: Player.cpp Player.h Object.h
	$(gpp_o) Player.cpp

ObjectList.o: ObjectList.cpp ObjectList.h Object.h
	$(gpp_o) ObjectList.cpp
	
run: main
	./main

clean:
	rm *.o main