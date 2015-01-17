#ifndef TILE_H
#define TILE_H
/* 
   A class for defining the properties and
   behavior of tiles in a mahjong game 
   >File created on 1/13/15
*/

#‌include <string>

class Tile
{
public:
    Tile(tile_suit suit, int val, int id);
    ~Tile();

    //an enum for representing the different suits
    //of a mahjong tile. For simplicity's sake, winds
    //and dragons will be considered suits of their
    //own, even though technically they are not
    typedef enum
    {
        invalid=0,
        pin,
        man,
        sou,
        wind,
        dragon
    }tile_suit;

    //functions for accessing the properties of a tile
  
    tile_suit getSuit();
    int getValue();
    int getId();

    bool isSuit(tile_suit suit);
    bool isSimple();
    bool isTerminal();
    bool isHonor();
    bool isWind();
    bool isDragon();

    //return a string representing the tile value
    std::string toString();
 protected:
    tile_suit suit;         //the suit of the tile
    int value;              //the value of the tile within its suit (i.e. 4 for 4 pin, 1 for east wind)
    int id;                 //unique utility id number for direct comparison (<0 for invalid tile, 0 and above for future reference?) e.g. is this the exact tile?
};

#endif
