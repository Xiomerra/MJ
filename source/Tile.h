#ifndef TILE_H
#define TILE_H
/* 
   A class for defining the properties and
   behavior of tiles in a mahjong game 
   >File created on 1/13/15
*/
#include <string>
#include <iostream>
using namespace std;

//don't know where to put these yet
//perhaps somewhere with a tileset class?
//these will NEVER change
const int tile_copies = 4;
const int suit_length = 9;
const int num_wind_tiles = 4;
const int num_dragon_tiles = 3;

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
    Tile(Suit suit, int val, int id, bool isDora = false, bool isRedFive = false);
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

	bool isDora();
	bool isRedFive();

	void makeDora();	//make this tile a dora tile?

    //return a string representing the tile value
    std::string toString();
 protected:
    Suit suit;         //the suit of the tile
    int value;              //the value of the tile within its suit (i.e. 4 for 4 pin, 1 for east wind)
    int id;                 //unique utility id number for direct comparison
							//	 - needed to verify this is the actual tile sent to the player during a draw.
	bool dora;				//is this tile have dora value? Default false
	bool redFive;			//is this tile a red five? default false
};

#endif
