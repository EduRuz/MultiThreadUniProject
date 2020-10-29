#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}

/**
	Returns true if the grid space in the direction passed is solid.
	@param Direction for solid check.
*/
bool Map::getIsSolid(DIRECTION direction)
{
	switch (dir) {
	case LEFT:
		return leftSolid;
		break;
	case RIGHT:
		return rightSolid;
		break;
	case UP:
		return upSolid;
		break;
	case DOWN:
		return downSolid;
		break;
	}
}


