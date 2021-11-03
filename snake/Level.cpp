#include "Level.h"

void Level::emptyArea() {
	for (unsigned short i = 0; i < area_w; i++) {
		for (unsigned short j = 0; j < area_h; j++) {
			area[i][j] = ' ';
		}
	}
}

void Level::updateSnakePos() {
	unsigned short snakeHeadX = this->snake.getHeadPos().x;
	unsigned short snakeHeadY = this->snake.getHeadPos().y;

	if (snakeHeadX >= this->area_w || snakeHeadY >= this->area_h) this->snake.crashSnake();
	else {
		this->emptyArea();

		for (auto i : snake.getCoords()) {
			this->area[i.x][i.y] = 0xB1;
		}
		this->area[snakeHeadX][snakeHeadY] = 0xB2;
		if (snakeHeadX == apple_x && snakeHeadY == apple_y)this->eatApple();

		this->area[this->apple_x][this->apple_y] = 'O';

		for (unsigned int i = 0; i < this->snake.getCoords().size() - 1; i++) {
			if (this->snake.getCoords().at(i) == this->snake.getHeadPos()) {
				this->snake.crashSnake();
				break;
			}
		}

		if (!this->snake.isCrashed()) {
			Coord nextcoord(snakeHeadX,snakeHeadY);
			switch (this->snake.getDir()) {
			case 'n':
				nextcoord.y--;
			case 's':
				if (snakeHeadY == area_h - 1 || snakeHeadY == 0) Sleep(this->snake.getFreq());
				else if (this->snake.getDir()=='s') nextcoord.y++;
				break;
			case 'e':
				nextcoord.x++;
			case 'w':
				if (snakeHeadX == area_w - 1 || snakeHeadX == 0) Sleep(this->snake.getFreq());
				else if (this->snake.getDir()=='w') nextcoord.x--;
				break;
			}
			for (auto i : this->snake.getCoords()) {
				if (i == nextcoord) {
					Sleep(this->snake.getFreq());
					break;
				}
			}
		}
	}
}

void Level::display() const {
	std::cout << char(0xC9);
	for (unsigned short i = 0; i < area_w; i++) {
		std::cout << char(0xCD);
	}

	std::cout << char(0xBB) << std::endl;

	for (unsigned short i = 0; i < area_h; i++) {
		std::cout << char(0xBA);
		for (unsigned short j = 0; j < area_w; j++) {
			std::cout << this->area[j][i];
		}
		std::cout << char(0xBA) << std::endl;
	}

	std::cout << char(0xC8);
	for (unsigned short i = 0; i < area_w; i++) {
		std::cout << char(0xCD);
	}
	std::cout << char(0xBC) << std::endl;
	//std::cout << this->snake.getHeadPos().x << '\t' << this->snake.getHeadPos().y << '\t' << this->snake.getLength() << std::endl;
	std::cout << "Score: " << this->snake.getLength()-5 << std::endl;
}

void Level::newApple() {
	bool appleSet = false;
	while (!appleSet) {
		this->apple_x = rand() % this->area_w;
		this->apple_y = rand() % this->area_h;
		for (auto i : this->snake.getCoords()) {
			if (i.x == apple_x && i.y == apple_y) {
				appleSet = false;
				break;
			}
			else appleSet = true;
		}
	}
}

void Level::eatApple() {
	this->snake.grow();
	this->newApple();
}

Level::Level() {
	this->emptyArea();
	this->newApple();
}