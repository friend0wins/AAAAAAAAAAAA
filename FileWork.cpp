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
		cout << "Õîòèòå ñîõðàíèòü îòñîðòèðîâàííûå äàííûå â ôàéë?" << endl;
		cout << "1 - ñîõðàíèòü äàííûå â ôàéë" << endl << "2 - âåðíóòüñÿ â ãëàâíîå ìåíþ" << endl;
		choice = InputInt();
		if (choice != Save and choice != Back)
			cout << "Òàêîãî âàðèàíòà íåò, ïîæàëóéñòà, ââåäèòå îäèí èç ïðåäñòàâëåííûõ âàðèàíòîâ." << endl << endl;
	}
}

void SaveInfo(vector <double>& vec) {
	string path;
	ofstream fout;
	int choice = 0;
	int choice1 = 0, choice2 = 0;
	do {
		cout << "Ââåäèòå ïóòü ê ôàéëó ñ êîòîðûì õîòèòå ðàáîòàòü: ";
		cin >> path;
		if (CheckFile(path)) {
			cout << "Ôàéë ïî çàäàííîìó ïóòè íàéäåí" << endl;
			do {
				cout << "âûáåðèòå âàðèàíò: " << endl;
				cout << "1 - ïåðåçàïèñàòü ôàéë" << endl;
				cout << "2 - èçìåíèòü âûáîð ôàéëà" << endl;
				choice1 = InputInt();
				switch (choice1) {
				case (EditAll):
					fout.open(path);
					if (!fout.is_open()) {
						cout << "Íå âûøëî îòêðûòü ôàéë äëÿ èçìåíåíèé, ïðîâåðüòå íàñòðîéêè ôàéëà, âîçìîæíî îí äîñòóïåí òîëüêî äëÿ ÷òåíèÿ" << endl << "ïîïðîáóéòå èçìåíèòü âûáîð ôàéëà" << endl;
						choice1 = Back;
					}
					break;
				case (Back):
					break;
				default:
					cout << "Òàêîãî âàðèàíòà íåò, âûáåðèòå èç ïðåäñòàâëåííûõ: " << endl;
				}
			} while (choice1 != EditAll and choice1 != Back);
		}
		else {
			cout << "Ôàéë ïî âàøåìó ïóòè íå íàéäåí, âû ìîæåòå ñîçäàòü ôàéë, ëèáî ïîïðîáîâàòü ââåñòè äðóãîé ïóòü" << endl;
			do {
				cout << "1 - ñîçäàòü íîâûé ôàéë" << endl << "2 - èçìåíèòü âûáîð ôàéëà" << endl;
				choice2 = InputInt();
				switch (choice2) {
				case (Create):
					fout.open(path);
					if (CheckFile(path))
						cout << "Ôàéë ñîçäàí." << endl;
					else
						cout << "Ôàéë ïî êàêîé-òî ïðè÷èíå íå âûøëî ñîçäàòü." << endl;
					break;
				case (DontCreate):
					break;
				default:
					cout << "Òàêîãî âàðèàíòà íåò, âûáåðèòå èç ïðåäñòàâëåííûõ: " << endl;
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
		cout << "Äàííûå óñïåøíî ñîõðàíåíû â ôàéëå." << endl;
	}
	fout.close();
}
