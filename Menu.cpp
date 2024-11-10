#include "Input.h"
#include "sort.h"
#include <iostream>
#include <vector>
#include "FileWork.h"

using namespace std;

enum MENU { Input = 1, InputFile, Quit };

//Âûâîä èíôîðìàöèè î ðàçðàáîò÷èêàõ
void MainInfo(void) {
	cout << "Çäðàâñòâóéòå" << endl;
	cout << "Ïðîãðàììó íàïèñàëè Øàìîòàéëîâ è Îáðàçöîâ, ãðóïïà 433" << endl;
}

//Âûâîä ìåíþ
void ChoiceInfo(void) {
	cout << "1 - Ââåñòè ìàññèâ âðó÷íóþ" << endl << "2 - Ââåñòè ìàññèâ èç ôàéëà" << endl;
	cout << "3 - Âûõîä èç ïðîãðàììû" << endl;
}

//Âûáîð ïóíêòà ìåíþ ïîëüçîâàòåëåì
int InputChoiceMenu(void) {
	int choice = 0;
	cout << "Âûáåðèòå íóæíîå äåéñòâèå :" << endl;
	ChoiceInfo();
	choice = InputInt();
	return choice;
}

//Ìåíþ
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
			cout << "Òàêîãî âàðèàíòà íåò, ïîæàëóéñòà, âûáåðèòå èç ïðåäñòàâëåííûõ" << endl;
		}
	} while (choice != Quit);
	cout << "Ñïàñèáî, ÷òî èñïîëüçóåòå íàøó ïðîãðàììó" << endl;
}



