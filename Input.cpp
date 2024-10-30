#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "sort.h"
#include "FileWork.h"
#include <fstream>

using namespace std;

enum CHOICE {No = 2};

bool CheckDigit(string word) {
	bool right = 1;
	char ch;
	for (int i = 0; i < word.size(); i++){
		ch = word[i];
		if (isdigit(ch) or /*ch == 'e' or*/ ch == '.' or ch == '+' or ch == '-')
			continue;
		else
			right = 0;
	}
	return right;
}

int InputInt() {
	string word;
	int value = 0;
	cin >> word;
	while (not cin.good() or not CheckDigit(word))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Вы ввели неподходящее значение, пожалуйста повторите ввод: ";
		cin >> word;
	}
	istringstream streamword(word);
	streamword >> value;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return value;
}

void InputDouble(vector <double> & array) {
	string str, word;
	double value = 0.;
	getline(cin, str);
	istringstream stream(str);
	while (stream >> word) {
		if (CheckDigit(word)) {
			istringstream streamword(word);
			streamword >> value;
			array.push_back(value);
		}
		else
			break;
	}
	if (!stream.eof()) {
		cout << "Строка имеет неправильный формат." << endl;
		cout << "В массив были записаны " << array.size() << " элементов." << endl;
	}
	else if (array.size() != 0)
		cout << "Ваши данные были записаны в массив." << endl;
}

void ShowArray(vector <double> array) {
	if (array.size() == 0)
		cout << "Массив не был заполнен данными, пожалуйста повторите ввод: " << endl;
	else {
		cout << "Массив введённый в программу: " << endl;
		for (int i = 0; i < array.size(); i++) {
			cout << array[i] << '\t';
			if (i % 10 == 9) cout << endl;
		}
		cout << endl;
	}
}

void InputArrayByUser() {
	vector <double> array;
	int choice = 0;
	cout << "Пожалуйста введите массив: ";
	while (array.size() == 0) {
		InputDouble(array);
		ShowArray(array);
	}
	Sort(array);
	SaveInfoMenu(choice);
	if (choice != No)
		SaveInfo(array);
	array.clear();
}

void InputArrayByFile() {
	vector <double> array;
	string path;
	ifstream fin;
	double value;
	int choice = 0;
	cout << "Введите путь к файлу из которого хотите считать данные: ";
	cin >> path;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	fin.open(path);
	if (!fin.is_open())
		cout << "Ошибка чтения файла" << endl;
	else {
		while (!fin.eof()) {
			while (fin >> value)
				array.push_back(value);
			if (!fin.eof())
				cout << "Во время считывания информации произошла ошибка, дальше считывать информацию из файла программа не будет." << endl;
		}
		if (array.size() == 0)
			cout << "Программа не считала ни одного элемента из файла." << endl;
	}
	fin.close();
	if (array.size() != 0) {
		ShowArray(array);
		Sort(array);
		SaveInfoMenu(choice);
		if (choice != No)
			SaveInfo(array);
		array.clear();
	}
}
