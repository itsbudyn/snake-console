#pragma once
#include "Header.h"
#include "Snake.h"

class Level {
private:
	const unsigned short area_w = 30;
	const unsigned short area_h = 15;
	unsigned short apple_x, apple_y;
	char area[30][15] = { ' ' };

	void emptyArea();
public:
	Snake snake;
	void updateSnakePos();
	void display() const;
	void newApple();
	void eatApple();
	Level();
};

