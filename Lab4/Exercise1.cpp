#include "stdio.h"
#include <iostream>
#include <iomanip>
#include <clocale>
#include <time.h>

#include <Windows.h> // console

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const int N = 8;

int* GetFirstMaxElementIndex(double *arr, int arrLength) { // находим индекс первого max элемента
	double maxValue = DBL_MIN;
	int maxIndex = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] > maxValue) {
			maxValue = arr[i];
			maxIndex = i;
		}
	}
	cout << "\nMAX: " << maxValue;
	return &maxIndex; // возвращаем указатель
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
		arr[i] = rand() % 101 - 50 + (double)rand() / RAND_MAX;
	}
}

void ShowArray(double *arr, int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		printf("%8.3lf",arr[i]) ;
	}
}

void PointA() {
	const int N1 = 6, N2 = 8;
	double A[N1], B[N2];

	srand(time(NULL));

	SetRandomArray(A, N1);
	cout << "\nМассив А\n";
	ShowArray(A, N1);

	int* maxElementIndex_A = GetFirstMaxElementIndex(A, N1);
	int Index_A = *maxElementIndex_A;
	cout << "\nИндекс первого max элемента: " << Index_A << "\n";
	

	SetRandomArray(B, N2);
	cout << "\nМассив B\n";
	ShowArray(B, N2);

	int* maxElementIndex_B = GetFirstMaxElementIndex(B, N2);
	int Index_B = *maxElementIndex_B;
	cout << "\nИндекс первого max элемента: " << Index_B << "\n";

	if (Index_A < Index_B) {
		printf("\nМаксимум в массиве А ближе к началу\n");
	}
	if (Index_A > Index_B) {
		printf("\nМаксимум в массиве B ближе к началу\n");
	}
	else {
		printf("\nМаксимумы равноудалены от начала массивов\n");
	}
}

void SetRandomMultiArray(int arr[][N], int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			arr[i][j] = rand() % 101 - 50 + (double)rand() / RAND_MAX;
		}
	}
}

void ShowMultiArray(int arr[][N], int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			// check to get form
			if (i > j-1) {
				SetConsoleTextAttribute(hConsole, 14);
				printf("%6d", arr[i][j]);
			}
			else {
				SetConsoleTextAttribute(hConsole, 12);
				printf("%6d", arr[i][j]);
			}
		}
		printf("\n");
	}
	SetConsoleTextAttribute(hConsole, 7);
}

int GetFormElementsSum(int arr[][N], int arrLength) {
	int sum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			// check to get form
			if (i > j - 1) {
				sum += arr[i][j];
			}
		}
	}
	return sum;
}

void PointB() {
	int arr[N][N];

	printf("\nДана целочисленная матрица 8x8. Создать функцию для  нахождения суммы элементов в заштрихованной области\n");
	SetRandomMultiArray(arr, N);
	ShowMultiArray(arr, N);
	printf("%d %s",GetFormElementsSum(arr, N), "\n");
}

void Exercise1() {
	
	PointA();
	PointB();
}