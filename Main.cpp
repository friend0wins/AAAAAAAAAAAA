#include "menu.h"
#include <clocale>
#include <iostream>
#include <windows.h>




int main(void) {
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Menu();
	return 0;
}