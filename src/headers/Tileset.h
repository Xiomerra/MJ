#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include "Tile.h"

class Tileset
{
public:
	Tileset();
	~Tileset();

	void generate(bool redFives);
	void shuffle();
protected:
	std::vector<Tile*> set;

};

#endif