
#include "stdio.h"
#include <iostream>
#include <iomanip>
#include <clocale>
#include <time.h>

using namespace std;

void Exercise2() // задание №2
{
    const int N = 8; // размер массива

    double squareArray[N][N]; // массив
    srand(time(NULL)); // рандомизация

    // создание массива случайных значений
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            squareArray[i][j] = rand() % 10;
        }
    }

    // печать матрицы 
    cout << "Массив (по умолчанию 8*8):\n";
    for (int i = 0; i < N; i++)
    {
        cout << endl;
        for (int j = 0; j < N; j++)
        {
            cout << setw(8) << setprecision(3) << squareArray[i][j] << ' ';
        }
    }

    // a)
    double sum = 0;
    // сумма элементов 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j < i) {
                sum += squareArray[i][j];
            }
        }
    }
    cout << fixed << setprecision(0) << "\n" << "Сумма элементов закрашенной области: " << sum << "\n";

    // b)
    const int arraySumLength = (int)(N / 2);
    double arraySumColumns[arraySumLength];
    int arraySumWriteId = 0;
    // сумма элементов 
    for (int i = 0; i < N; i++)
    {
        int columnSum = 0;
        if (i % 2 != 0) { // если столбец нечетный
            for (int j = 0; j < N; j++)
            {
                columnSum += squareArray[j][i]; // находим сумму

                // добавляем в массив перед концом столбца
                if (j + 1 == N) {
                    arraySumColumns[arraySumWriteId] = (double)columnSum;
                    arraySumWriteId++;
                }
            }
        }
    }

    cout << "Массив сумм элементов нечетных столбцов: " << "\n";
    for (int j = 0; j < (int)(N / 2); j++) {
        cout << "\t" << arraySumColumns[j];
    }
}
