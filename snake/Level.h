#pragma once
#include "Header.h"
#include "Snake.h"

class Level {
private:
	const unsigned short area_w = AREA_W;
	const unsigned short area_h = AREA_H;
	unsigned short apple_x, apple_y;
	char area[AREA_W][AREA_H] = { ' ' };

	void emptyArea();
public:
	Snake snake;
	void updateSnakePos();
	void display() const;
	void newApple();
	void eatApple();
	Level();
};

