// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
		cout << "Задание 1.\nСоздать функцию для поиска положения (индекса) первого отрицательного элемента произвольного массива целых чисел. Определить среднее арифметическое элементов второй части массива. \n";
		Exercise1();

		cout << "\nЗадание 2.\nДана целочисленная матрица NxN\nСоздать функцию, которая возвращает  количество нулей в заданной строке заштрихованной области.Отразить на экране результаты для всех строк.\n";
		Exercise2();

		cout << "Продолжить выполнение? 1 - YES\n";
		cin >> ans;
		if (ans != '1') {
			break;
		}
		cout << "\n";
	}
	
	return 0;
}
