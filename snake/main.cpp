#include "Header.h"
#include "Game.h"

int main() {
	while (1) {
		Game g;
		std::cout << "Continue? [y/N]: ";
		char choice;
		std::cin.get(choice);
		std::cin.ignore();
		if (choice != 'y')break;
	}
}