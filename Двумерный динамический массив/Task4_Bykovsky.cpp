//Задача 4, вариант 9. Поменять четные и нечетные строки местами. Быковский Данила, 4 группа, ФКН, ИСИТ

#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int numOfLines, numOfCollumns, ** x, i, j;

	cout << "Введите число строк: ";
	cin >> numOfLines;
	cout << "Введите число столбцов: ";
	cin >> numOfCollumns;

	x = new int* [numOfLines];

	for (i = 0; i < numOfLines; i++) {
		x[i] = new int[numOfCollumns];
	}

	for (i = 0; i < numOfLines; i++) {
		for (j = 0; j < numOfCollumns; j++) {
			x[i][j] = rand() % 10;
		}
	}

	for (i = 0; i < numOfLines; i++) {
		for (j = 0; j < numOfCollumns; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
	cout << "" << endl;

	for (i = 0; i < numOfLines; i += 2) {
		if ((i == numOfLines - 1) && ((numOfLines % 2) != 0)) {
		}
		else {
			swap(x[i], x[i + 1]);
		}

	}

	for (i = 0; i < numOfLines; i++) {
		for (j = 0; j < numOfCollumns; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}

	for (i = 0; i < numOfLines; i++) {
		delete[] x[i];
	}

	delete[] x;
}