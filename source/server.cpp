//server.cpp
//created 1/16/2015
//entry point for the server program code

#ifdef XMJ_SERVER

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
	int id = 0;
	Suit suit = Suit::pin;
	//four copies
	for (int i = 0; i < 4; i++)
	{
		for (int val = 1; val < 10; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			tileset.push_back(t);
		}
	}

	suit = Suit::man;
	for (int i = 0; i < 4; i++)
	{
		for (int val = 1; val < 10; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			tileset.push_back(t);
		}
	}

	suit = Suit::sou;
	for (int i = 0; i < 4; i++)
	{
		for (int val = 1; val < 10; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			tileset.push_back(t);
		}
	}

	suit = Suit::wind;
	for (int i = 0; i < 4; i++)
	{
		for (int val = 1; val < 5; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			tileset.push_back(t);
		}
	}

	suit = Suit::dragon;
	for (int i = 0; i < 4; i++)
	{
		for (int val = 1; val < 4; val++)
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

#endif