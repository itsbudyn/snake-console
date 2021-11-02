#include "Snake.h"

Coord Snake::getHeadPos() const {
	return this->coords.back();
}

std::deque<Coord> Snake::getCoords() const {
	return this->coords;
}

void Snake::grow() {
	this->length++;
}

void Snake::changeDir(const char dir) {
	if (this->dir != dir) {
		switch (dir) {
		case 'n':
			if (this->dir != 's')this->dir = dir;
			break;
		case 'e':
			if (this->dir != 'w')this->dir = dir;
			break;
		case 's':
			if (this->dir != 'n')this->dir = dir;
			break;
		case 'w':
			if (this->dir != 'e')this->dir = dir;
			break;
		}
	}
}

void Snake::moveSnake() {
	Coord newCoord = this->coords.back();
	bool stopped = false;
	switch (this->dir) {
	case 'n':
		newCoord.y--;
		break;
	case 'e':
		newCoord.x++;
		break;
	case 's':
		newCoord.y++;
		break;
	case 'w':
		newCoord.x--;
		break;
	default:
		stopped = true;
		break;
	}
	if (stopped) return;
	this->coords.push_back(newCoord);
	if (this->coords.size() > this->length) this->coords.pop_front();
}

void Snake::crashSnake() {
	this->crashed = true;
}

bool Snake::isCrashed() const {
	return this->crashed;
}

unsigned short Snake::getLength() const {
	return this->length;
}

unsigned short Snake::getFreq() const {
	return this->freq;
}

char Snake::getDir() const {
	return this->dir;
}

Snake::Snake() {
	this->coords.push_back(Coord(7,4));
}