#include "Coord.h"
bool Coord::operator==(const Coord a) {
	if (this == &a) return true;
	else if (this->x == a.x && this->y == a.y)return true;
	else return false;
}