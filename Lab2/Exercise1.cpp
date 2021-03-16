
#include "stdio.h"
#include <iostream>
#include <time.h>

using namespace std;

int maxElementId(double arr[], int length) { // находим индекс максимального элемента

    double maxValue = -99999;
    int maxId = 0;
    for (int i = 0; i < length; i++) {
        if (maxValue < arr[i]) {
            maxValue = arr[i];
            maxId = i;
        }
    }
    return maxId;
}

double sumElementsAfter(double arr[], int length, int index) { // вычисляем сумму элементов после элемента с заданным индексом
    double sum = 0;
    for (int i = index + 1; i < length; i++) {
        cout << arr[i] << "\t";
        sum += arr[i];
    }
    return sum;
}

void Exercise1() // задание №1
{
    const int N = 10; // размер массива

    double X[N]; // массив
    srand(time(NULL)); // рандомизация

    // создание массива случайных значений
    for (int i = 0; i < N; i++) {
        X[i] = rand() % 100; 
    }

    // выводим массив
    cout << "Массив X(N):\n";
    for (int i = 0; i < N; i++) {
        cout << X[i] << "\t";
    }

    // ответ (сумма)
    cout << "\nСумма элементов = " << sumElementsAfter(X, N, maxElementId(X, N));
}
