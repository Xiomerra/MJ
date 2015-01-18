#ifndef TILE_H
#define TILE_H
/* 
   A class for defining the properties and
   behavior of tiles in a mahjong game 
   >File created on 1/13/15
*/
#include <string>

//an enum for representing the different suits
//of a mahjong tile. For simplicity's sake, winds
//and dragons will be considered suits of their
//own, even though technically they are not
enum class Suit : int
{
	invalid,
	pin,
	man,
	sou,
	wind,
	dragon
};

class Tile
{
public:
    Tile(Suit suit, int val, int id, bool isDora);
    ~Tile();

    //functions for accessing the properties of a tile
  
    Suit getSuit();
    int getValue();
    int getId();

    bool isSuit(Suit suit);
    bool isSimple();
    bool isTerminal();
    bool isHonor();
    bool isWind();
    bool isDragon();

	void makeDora();	//make this tile a dora tile?

    //return a string representing the tile value
    std::string toString();
 protected:
    Suit suit;         //the suit of the tile
    int value;              //the value of the tile within its suit (i.e. 4 for 4 pin, 1 for east wind)
    int id;                 //unique utility id number for direct comparison (<0 for invalid tile, 0 and above for future reference?) e.g. is this the exact tile?
	bool dora;				//is this tile have dora value? Default false
};

#endif
