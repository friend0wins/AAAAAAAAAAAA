#include <vector>
#include <iostream>

using namespace std;

void ShowSortArray(vector <double> vec) {
	cout << endl << "Отсортированный массив: " << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << '\t';
		if (i % 10 == 9) cout << endl;
	}
	cout << endl;
}

void Sort(vector <double>& vec) {
	int jump = vec.size() - 1;
	double fact = 1.25;
	while (jump >= 1){
		for (int i = 0; i + jump < vec.size(); i++)
		{
			if (vec[i] > vec[i + jump])
			{
				swap(vec[i], vec[i + jump]);
			}
		}
		jump /= fact;
	}
	ShowSortArray(vec);
}