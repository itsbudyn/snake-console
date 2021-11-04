#pragma once
#include "Header.h"
#include "Coord.h"

class Snake {
private:
	std::deque<Coord> coords;
	bool crashed = 0;
	unsigned short length = 5;
	unsigned short freq = 100;
	char dir = '0';
public:
	Coord getHeadPos() const;
	std::deque<Coord> getCoords() const;
	void grow();
	void changeDir(const char dir);
	void moveSnake();
	void crashSnake();
	bool isCrashed() const;
	unsigned short getLength() const;
	unsigned short getFreq() const;
	void setFreq(const unsigned short freq);
	char getDir() const;
	Snake();
};