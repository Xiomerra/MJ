#include "Tile.h"

Tile::Tile(tile_suit suit, int val, int id)
{
	this->suit = suit;
	this->value = val;
	this->id = id;
}

Tile::~Tile()
{
}


//general accessors
tile_suit getSuit()
{
	return suit;
}

int getValue()
{
	return value;
}

int getId()
{
	return id;
}

//checkers (different name?)
bool isSuit(tile_suit testSuit)
{
	return suit == testSuit;
}

//a simple is any non-terminal, non-honor tile
bool isSimple()
{
	return (!isTerminal() && !isHonor());
}

bool isTerminal()
{
	//if tile is honor, value is irrelevant
	if(isHonor())
		return false;	
	//terminals are 1 or 9 valued tiles
	return (value == 1 || value == 9);
}

bool isHonor()
{
	return (isWind() || isDragon());
}

bool isWind()
{
	return (suit == tile_suit::wind);
}

bool isDragon()
{
	return (suit == tile_suit::dragon);
}

