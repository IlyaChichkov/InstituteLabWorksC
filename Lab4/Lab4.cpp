// Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Exercise1.h"
#include "Exercise2.h"

using namespace std;

int main()
{

	setlocale(0, "Russian");
	char ans = '1';
	while (true) {
		cout << "Задание 1.\nСоздать функцию для поиска положения максимального элемента произвольного массива вещественных чисел. Вернуть указатель на максимальный элемент.\n";
		Exercise1();

		cout << "Продолжить выполнение? 1 - YES\n";
		cin >> ans;
		if (ans != '1') {
			break;
		}
		cout << "\n";
	}

	return 0;
}
