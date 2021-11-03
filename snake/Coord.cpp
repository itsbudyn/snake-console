#include "Coord.h"
bool Coord::operator==(const Coord a) const {
	if (this == &a) return true;
	else if (this->x == a.x && this->y == a.y)return true;
	else return false;
}
bool Coord::operator!=(const Coord a) const {
	if (this == &a) return false;
	else if (this->x == a.x && this->y == a.y)return false;
	else return true;
}