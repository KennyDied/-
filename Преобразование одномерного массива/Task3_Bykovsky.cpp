//Задача 3, вариант был выдан преподавателем на паре. Продублировать по три элемента. Быковский Данила, 4 группа, ФКН, ИСИТ


#include <iostream>
using namespace std;

int main() {
setlocale(LC_ALL, "Russian");
tryCatch:
	cout << "Введите количествово элементов, кратное трем: ";
	int n;
	cin >> n;

	if (n % 3 != 0) {
		cout << "Ошибка ввода, попробуйте еще раз." << endl;
		goto tryCatch;
	}

	char* input = new char[128];

	cout << "Введите элементы: ";
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	char* answer;
	answer = new char[n * 2];
	for (int i = 0; i < n / 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(answer + j + 6 * i) = *input;
			*(answer + j + 6 * i + 3) = *input;
			*input++;
		}
	}

	for (int i = 0; i < n * 2; i++)
	{
		cout << answer[i];
	}
	return 0;

	delete[]input;
	delete[]answer;
}