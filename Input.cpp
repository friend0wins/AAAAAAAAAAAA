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
		cout << "Âû ââåëè íåïîäõîäÿùåå çíà÷åíèå, ïîæàëóéñòà, ïîâòîðèòå ââîä: ";
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
		cout << "Ñòðîêà èìååò íåïðàâèëüíûé ôîðìàò." << endl;
		cout << "Â ìàññèâ áûëè çàïèñàíû " << array.size() << " ýëåìåíòîâ." << endl;
	}
	else if (array.size() != 0)
		cout << "Âàøè äàííûå áûëè çàïèñàíû â ìàññèâ." << endl;
}

void ShowArray(vector <double> array) {
	if (array.size() == 0)
		cout << "Ìàññèâ íå áûë çàïîëíåí äàííûìè, ïîæàëóéñòà, ïîâòîðèòå ââîä: " << endl;
	else {
		cout << "Ìàññèâ ââåä¸ííûé â ïðîãðàììó: " << endl;
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
	cout << "Вâåäèòå ìàññèâ: ";
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
	cout << "Ââåäèòå ïóòü ê ôàéëó èç êîòîðîãî õîòèòå ñ÷èòàòü äàííûå: ";
	cin >> path;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	fin.open(path);
	if (!fin.is_open())
		cout << "Îøèáêà ÷òåíèÿ ôàéëà" << endl;
	else {
		while (!fin.eof()) {
			while (fin >> value)
				array.push_back(value);
			if (!fin.eof())
				cout << "Âî âðåìÿ ñ÷èòûâàíèÿ èíôîðìàöèè ïðîèçîøëà îøèáêà, äàëüøå ñ÷èòûâàòü èíôîðìàöèþ èç ôàéëà ïðîãðàììà íå áóäåò." << endl;
		}
		if (array.size() == 0)
			cout << "Ïðîãðàììà íå ñ÷èòàëà íè îäíîãî ýëåìåíòà èç ôàéëà." << endl;
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
