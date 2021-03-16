// Lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "stdio.h"
#include <iostream>
#include <time.h>
#include "Exercise1.h";
#include "Exercise2.h";

using namespace std;

int main()
{
    setlocale(0, "Russian");
    
    cout << "\nЗадание 1:";
    cout << "\nВ массиве Х(N) найти сумму элементов, расположенных после максимального элемента.\n";
    Exercise1();
    cout << "\n";
    cout << "\nЗадание 2:";
    cout << "\nДана целочисленная матрица 8x8. Найти сумму элементов в заштрихованной области. Сформировать одномерный массив, состоящий из сумм элементов нечетных столбцов.\n";
    Exercise2();
    cout << "\n";
    return 0;
}
