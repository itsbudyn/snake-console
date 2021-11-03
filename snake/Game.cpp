#include "Game.h"

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
				switch (_getch()) {
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