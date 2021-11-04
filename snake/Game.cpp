#include "Game.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27

void Game::ShowConsoleCursor(const bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

Game::Game() {
	this->ShowConsoleCursor(false);
	srand(time(NULL));

	system("cls");

	while (!this->lv.snake.isCrashed()) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		this->lv.updateSnakePos();
		this->lv.display();

		if (this->lv.snake.isCrashed())break;
		else {
			Sleep(this->lv.snake.getFreq());
			if (_kbhit()) {

				unsigned char c =_getch();
				if (c==224){
					switch(_getch()){
					case KEY_UP:
						c='w';
						break;
					case KEY_LEFT:
						c='a';
						break;
					case KEY_DOWN:
						c='s';
						break;
					case KEY_RIGHT:
						c='d';
						break;
					}
				}
				switch (c) {
				case 'w':
					this->lv.snake.changeDir('n');
					break;
				case 'a':
					this->lv.snake.changeDir('w');
					break;
				case 's':
					this->lv.snake.changeDir('s');
					break;
				case 'd':
					this->lv.snake.changeDir('e');
					break;
				case KEY_ESC:
				case 'q':
					this->lv.snake.crashSnake();
					break;
				}
			}
			this->lv.snake.moveSnake();
		}
	}
	std::cout << "GAME OVER!" << std::endl;
	this->ShowConsoleCursor(true);
}