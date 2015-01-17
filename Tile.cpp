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

//other
std::string toString()
{
	std::string s;
	s += "[";
	//determine the suit first
	switch(suit)
	{
	case tile_suit::pin:
		s += "p";
		break;
	case tile_suit::man:
		s += "m";
		break;
	case tile_suit::sou:
		s += "s";
		break;
	case tile_suit::wind:
		switch(value)
		{
		case 1:
			return s + "east]";
		case 2:
			return s + "south]";
		case 3:
			return s + "west]";
		case 4:
			return s + "north]";
		default:
			return "[invalid]";
		}
		break;
	case tile_suit::dragon:
		switch(value)
		{
		case 1:
			return s + "white]";
		case 2:
			return s + "green]";
		case 3:
			return s + "red]";
		default:
			return "[invalid]";
		}
		break;
	default:
		return "[invalid]";
	}

	//now for numbers
	if(value > 0 && value < 10)
		return s + std::to_string(value) + "]";
	else return "[invalid]";

	//if all else fails (somehow) return invalid
	return "[invalid]";
	
}



///NOTE: need unit tests
