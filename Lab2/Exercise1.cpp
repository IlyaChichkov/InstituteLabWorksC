
#include "stdio.h"
#include <iostream>
#include <time.h>

using namespace std;

int maxElementId(double arr[], int length) { // ������� ������ ������������� ��������

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

double sumElementsAfter(double arr[], int length, int index) { // ��������� ����� ��������� ����� �������� � �������� ��������
    double sum = 0;
    for (int i = index + 1; i < length; i++) {
        cout << arr[i] << "\t";
        sum += arr[i];
    }
    return sum;
}

void Exercise1() // ������� �1
{
    const int N = 10; // ������ �������

    double X[N]; // ������
    srand(time(NULL)); // ������������

    // �������� ������� ��������� ��������
    for (int i = 0; i < N; i++) {
        X[i] = rand() % 100; 
    }

    // ������� ������
    cout << "������ X(N):\n";
    for (int i = 0; i < N; i++) {
        cout << X[i] << "\t";
    }

    // ����� (�����)
    cout << "\n����� ��������� = " << sumElementsAfter(X, N, maxElementId(X, N));
}