all:
	cd source

MJ-server: server.o Tile.o
	g++ server.o Tile.o -o bin/MJ-server

MJ-client: client.o
	g++ client.o -o bin/MJ-client

server.o: source/server.cpp
	g++ -c source/server.cpp

client.o: client.cpp
	g++ -c client.cpp

Hand.o: Hand.cpp
	g++ -c Hand.cpp

Tileset.o: Tileset.cpp
	g++ -c Tileset.cpp

Tile.o: source/Tile.cpp
	g++ -c source/Tile.cpp

clean:
	rm -rf *o
