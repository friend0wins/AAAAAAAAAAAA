#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Input.h"

enum ChoiceMenu { Save = 1, Back};
enum WorkwithNonExistsFile { Create = 1, DontCreate };
enum WorkWithExistFile { EditAll = 1 };

using namespace std;

bool CheckFile(string path) {
	struct stat statbuf[100];
	if (!stat(path.c_str(), statbuf))
		return true;
	else
		return false;
}


void SaveInfoMenu(int& choice) {
	while (choice != Save and choice != Back) {
		cout << "Хотите сохранить отсортированные данные в файл?" << endl;
		cout << "1 - сохранить данные в файл" << endl << "2 - вернуться в главное меню" << endl;
		choice = InputInt();
		if (choice != Save and choice != Back)
			cout << "Такого варианта нет, пожалуйста введите один из представленных вариантов." << endl << endl;
	}
}

void SaveInfo(vector <double>& vec) {
	string path;
	ofstream fout;
	int choice = 0;
	int choice1 = 0, choice2 = 0;
	do {
		cout << "Введите путь к файлу с которым хотите работать: ";
		cin >> path;
		if (CheckFile(path)) {
			cout << "Файл по заданному пути найден" << endl;
			do {
				cout << "выберите вариант: " << endl;
				cout << "1 - перезаписать файл" << endl;
				cout << "2 - изменить выбор файла" << endl;
				choice1 = InputInt();
				switch (choice1) {
				case (EditAll):
					fout.open(path);
					if (!fout.is_open()) {
						cout << "Не вышло открыть файл для изменений, проверьте настройки файла, возможно он доступен только для чтения" << endl << "попробуйте изменить выбор файла" << endl;
						choice1 = Back;
					}
					break;
				case (Back):
					break;
				default:
					cout << "Такого варианта нет, выберите из представленных: " << endl;
				}
			} while (choice1 != EditAll and choice1 != Back);
		}
		else {
			cout << "Файл по вашему пути не найден, вы можете создать файл, либо попробовать ввести другой путь" << endl;
			do {
				cout << "1 - создать новый файл" << endl << "2 - изменить выбор файла" << endl;
				choice2 = InputInt();
				switch (choice2) {
				case (Create):
					fout.open(path);
					if (CheckFile(path))
						cout << "Файл создан." << endl;
					else
						cout << "Файл по какой-то причине не вышло создать." << endl;
					break;
				case (DontCreate):
					break;
				default:
					cout << "Такого варианта нет, выберите из представленных: " << endl;
					break;
				}
			} while (choice2 != Create and choice2 != DontCreate);
		}
	} while (choice1 != EditAll and choice2 != Create);
	choice1 = 0;
	choice2 = 0;
	if (CheckFile(path) and (fout.is_open())) {
		for (int i = 0; i < size(vec); i++) {
			fout << vec[i] << " ";
			if (i % 11 == 10)
				fout << endl;
		}
		cout << "Данные успешно сохранены в файле." << endl;
	}
	fout.close();
}