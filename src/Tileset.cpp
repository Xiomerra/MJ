#include "Tileset.h"
// A class for generating and accessing a tileset
// the tileset changes depending upon what specific variation of
// mahjong you are playing
// Created 1/19/20015

Tileset::Tileset()
{

}

Tileset::~Tileset()
{
	//clean up the set
	for (auto it = set.begin(); it != set.end(); it++)
	{
		delete (*it);

	}
}

void Tileset::generate(bool redFives)
{
	//make sure the set is empty
	if (set.size() != 0)
	{
		cout << "error: cannot generate, set already generated. Perhaps clear first?" << endl;
	}
	int id = 0;	//note: assignment of tile ids needs to be somehow not easily predictable to clients?
	//we can't just not send them over because a client can falsify a packet and we need
	//a way to verify the tile they send is the one we sent them...so the id stays! The
	//problem is how it stays. I need to look up internet security
	//TODO: modify how id's are allocated
	Suit suit = Suit::pin;
	//four copies
	for (int i = 0; i < tile_copies; i++)
	{
		for (int val = 1; val <= suit_length; val++)
		{
			Tile *t;
			if (redFives && (i == 1 && val == 5))
			{
				t = new Tile(suit, val, id++, true);
			}
			else
			{
				t = new Tile(suit, val, id++, false);
			}
			set.push_back(t);
		}
	}

	suit = Suit::man;
	for (int i = 0; i < tile_copies; i++)
	{
		for (int val = 1; val <= suit_length; val++)
		{
			Tile *t;
			if (redFives && (i == 1 && val == 5))
			{
				t = new Tile(suit, val, id++, true);
			}
			else
			{
				t = new Tile(suit, val, id++, false);
			}
			set.push_back(t);
		}
	}

	suit = Suit::sou;
	for (int i = 0; i < tile_copies; i++)
	{
		for (int val = 1; val <= suit_length; val++)
		{
			Tile *t;
			if (redFives && (i == 1 && val == 5))
			{
				t = new Tile(suit, val, id++, true);
			}
			else
			{
				t = new Tile(suit, val, id++, false);
			}
			set.push_back(t);
		}
	}

	suit = Suit::wind;
	for (int i = 0; i < tile_copies; i++)
	{
		for (int val = 1; val <= num_wind_tiles; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			set.push_back(t);
		}
	}

	suit = Suit::dragon;
	for (int i = 0; i < tile_copies; i++)
	{
		for (int val = 1; val <= num_dragon_tiles; val++)
		{
			Tile* t = new Tile(suit, val, id++, false);
			set.push_back(t);
		}
	}
}