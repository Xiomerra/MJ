//server.cpp
//created 1/16/2015
//entry point for the server program code

#include <iostream>
#include <vector>
using namespace std;

#include "Tile.h"

int main()
{
	cout << "Hello world from XMJ server!" << endl;

	cout << "testing Tile.cpp" << endl;

	//generate a set of tiles
	vector<Tile*> tileset;
	int id = 0;	//note: assignment of tile ids needs to be somehow not easily predictable to clients?
				//we can't just not send them over because a client can falsify a packet and we need
				//a way to verify the tile they send is the one we sent them...so the id stays! The
				//problem is how it stays. I need to look up internet security
	Suit suit = Suit::pin;
	//four copies
	for (int i = 0; i < tile_copies; i++)
	{
		for (int val = 1; val <= suit_length; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			tileset.push_back(t);
		}
	}

	suit = Suit::man;
	for (int i = 0; i < tile_copies; i++)
	{
		for (int val = 1; val <= suit_length; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			tileset.push_back(t);
		}
	}

	suit = Suit::sou;
	for (int i = 0; i < tile_copies; i++)
	{
		for (int val = 1; val <= suit_length; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			tileset.push_back(t);
		}
	}

	suit = Suit::wind;
	for (int i = 0; i < tile_copies; i++)
	{
		for (int val = 1; val <= num_wind_tiles; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			tileset.push_back(t);
		}
	}

	suit = Suit::dragon;
	for (int i = 0; i < tile_copies; i++)
	{
		for (int val = 1; val <= num_dragon_tiles; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			tileset.push_back(t);
		}
	}

	//now print out the set
	for (auto it = tileset.begin(); it != tileset.end(); it++)
	{
		cout << (*it)->toString() << endl;
	}

	cin.get();






	return 0;
}