#include "Input.h"
#include "sort.h"
#include <iostream>
#include <vector>
#include "FileWork.h"

using namespace std;

enum MENU { Input = 1, InputFile, Quit };

//Вывод информации о разработчиках
void MainInfo(void) {
	cout << "Здравствуйте" << endl;
	cout << "Программу написали Шамотайлов и Образцов, группа 433" << endl;
}

//Вывод меню
void ChoiceInfo(void) {
	cout << "1 - Ввести массив вручную" << endl << "2 - Ввести массив из файла" << endl;
	cout << "3 - Выход из программы" << endl;
}

//Выбор пункта меню пользователем
int InputChoiceMenu(void) {
	int choice = 0;
	cout << "Выберите нужное действие :" << endl;
	ChoiceInfo();
	choice = InputInt();
	return choice;
}

//Меню
void Menu() {
	int choice = 0;
	MainInfo();
	do {
		choice = InputChoiceMenu();
		switch (choice) {
		case (Input):
			InputArrayByUser();
			break;
		case(InputFile):
			InputArrayByFile();
			break;
		case(Quit):
			break;
		default:
			cout << "Такого варианта нет, пожалуйста выберите из представленных" << endl;
		}
	} while (choice != Quit);
	cout << "Спасибо, что используете нашу программу" << endl;
}



