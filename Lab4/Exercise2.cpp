#include "stdio.h"
#include <iostream>
#include <iomanip>
#include <clocale>
#include <time.h>

#include <Windows.h> // console

using namespace std;

HANDLE hConsole1 = GetStdHandle(STD_OUTPUT_HANDLE);

const int N = 8;

int* GetOddColumnSum(int arr[][N], int arrLength) { // сумма нечетных столбцов
	const int b = N / 2;
	static int oddSumArr[b] = {};
	int oddArrIndex = 0;
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			if (i % 2 != 0) {
				oddSumArr[oddArrIndex] += arr[j][i];

				if (j + 1 >= arrLength) {

					oddArrIndex++;
				}
			}
		}
	}
	return oddSumArr;
}

void SetRandomMultiArray1(int arr[][N], int arrLength) { // рандомный массив
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			arr[i][j] = rand() % 201 - 100;
		}
	}
}

/// <SHOW ARRAY FUNCTIONS>
void ShowMultiArray1(int arr[][N], int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			// check to get form
			if (i > j - 1) {
				printf("%6d", arr[i][j]);
			}
			else {
				printf("%6d", arr[i][j]);
			}
		}
		printf("\n");
	}
}

void ShowArray(int *arr, int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		printf("%5d", arr[i]);
	}
}

void ShowMultiArrayColored(int arr[][N], int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			// check to get form
			if (i > j - 1) {
				SetConsoleTextAttribute(hConsole1, 14);
				printf("%6d", arr[i][j]);
			}
			else {
				SetConsoleTextAttribute(hConsole1, 12);
				printf("%6d", arr[i][j]);
			}
		}
		printf("\n");
	}
	SetConsoleTextAttribute(hConsole1, 7);
}
/// </SHOW ARRAY FUNCTIONS>

int* GetFigureMaxAndMin(int arr[][N], int arrLength) { // поиск MAX и MIN в областе массива
	int max = INT_MIN;
	int min = INT_MAX;
	
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			// условие области
			if (i > j - 1) {
				if (arr[i][j] > max) {
					max = arr[i][j];
				}

				if (arr[i][j] < min) {
					min = arr[i][j];
				}
			}
		}
	}

	static int maxAndMinArray[2] = { max, min };
	return maxAndMinArray;
}

void Exercise2() {

	cout << "А)\n";
	int squareArray[N][N]; // создаем матрицу

	// присваиваем рандомное значение, отображаем в консоле
	SetRandomMultiArray1(squareArray, N);
	ShowMultiArray1(squareArray, N);

	int *arr;
	arr = GetOddColumnSum(squareArray, N); // получаем массив сум элементов нечетных столбцов
	
	for (int i = 0; i < N / 2; i++) {
		printf("%s %d %s %4d %s", "Сумма ", i+1, " столбца: ", arr[i], "\n");
	}

	cout << "\nБ) Дана целочисленная матрица NxN. Создать функцию, которая возвращает 2 значения: минимум и максимум заштрихованной области. \n";
	// присваиваем рандомное значение, отображаем в консоле
	SetRandomMultiArray1(squareArray, N);
	ShowMultiArrayColored(squareArray, N);

	arr = GetFigureMaxAndMin(squareArray, N);
	printf("%s %4d %s", "MAX: ", arr[0], "\n");
	printf("%s %4d %s", "MIN: ", arr[1], "\n");
}