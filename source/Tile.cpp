#include "Tile.h"

Tile::Tile(Suit suit, int val, int id, bool isDora, bool isRedFive)
{
	this->suit = suit;
	this->value = val;
	this->id = id;
	dora = isDora;
	redFive = isRedFive;
	if (isRedFive &&  !isDora)
	{
		cout << "warning: red five, but not dora, are you sure?" << endl;
	}
}

Tile::~Tile()
{
}


//general accessors
Suit Tile::getSuit()
{
	return suit;
}

int Tile::getValue()
{
	return value;
}

int Tile::getId()
{
	return id;
}

//checkers (different name?)
bool Tile::isSuit(Suit testSuit)
{
	return suit == testSuit;
}

//a simple is any non-terminal, non-honor tile
bool Tile::isSimple()
{
	return (!isTerminal() && !isHonor());
}

bool Tile::isTerminal()
{
	//if tile is honor, value is irrelevant
	if(isHonor())
		return false;	
	//terminals are 1 or 9 valued tiles
	return (value == 1 || value == 9);
}

bool Tile::isHonor()
{
	return (isWind() || isDragon());
}

bool Tile::isWind()
{
	return (suit == Suit::wind);
}

bool Tile::isDragon()
{
	return (suit == Suit::dragon);
}

bool Tile::isDora()
{
	return dora;
}

bool Tile::isRedFive()
{
	return redFive;
}

void Tile::makeDora()
{
	dora = true;
}

//other
std::string Tile::toString()
{
	std::string s;
	s += "[";
	//determine the suit first
	switch(suit)
	{
	case Suit::pin:
		s += "p";
		break;
	case Suit::man:
		s += "m";
		break;
	case Suit::sou:
		s += "s";
		break;
	case Suit::wind:
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
	case Suit::dragon:
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
