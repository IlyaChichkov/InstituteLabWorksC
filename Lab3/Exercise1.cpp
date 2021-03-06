#include "stdio.h"
#include <iostream>
#include <time.h>

using namespace std;

int GetFirstNegativeIndex(double *arr, int arrLength) { // find first negative element
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] < 0) {
			return i;
		}
	}
	return -1;
}

double GetArrayAverage(double *arr, int arrLength, int fromIndex = 0) {
	double average = 0;
	for (int i = fromIndex; i < arrLength; i++)
	{
		average += arr[i];
	}
	cout << "Average: " << average;
	return (double)average / (double)(arrLength - fromIndex);
}

void SetRandomArray(double *arr, int arrLength) {
	for (int i = 0; i < arrLength; i++) 
	{
		arr[i] = rand() % 100 - 50;
	}
}

void ShowArray(double *arr, int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << '\t';
	}
}

void Exercise1() {
	const int N1 = 6, N2 = 8;
	double A[N1], B[N2];

	srand(time(NULL));
	
	SetRandomArray(A, N1);
	cout << "\n?????? ?\n";
	ShowArray(A, N1);

	cout << "\n?????? ??????? ?????????????? ????????: " << GetFirstNegativeIndex(A, N1) << "\n";
	cout << "\n??????? ??????????????: " << GetArrayAverage(A,N1, GetFirstNegativeIndex(A, N1)  + 1) << "\n\n";

	SetRandomArray(B, N2);
	cout << "\n?????? B\n";
	ShowArray(B, N2);

	cout << "\n?????? ??????? ?????????????? ????????: " << GetFirstNegativeIndex(B, N2) << "\n";
	cout << "\n??????? ??????????????: " << GetArrayAverage(B, N2, GetFirstNegativeIndex(B, N2) + 1) << "\n";
}