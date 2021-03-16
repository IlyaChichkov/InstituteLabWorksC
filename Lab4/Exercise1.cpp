#include "stdio.h"
#include <iostream>
#include <time.h>

using namespace std;

int GetFirstMaxElementIndex(double *arr, int arrLength) { // searching for the first max element of array
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
	return maxIndex;
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

void Exercise1() {
	const int N1 = 6, N2 = 8;
	double A[N1], B[N2];

	srand(time(NULL));
	
	SetRandomArray(A, N1);
	cout << "\nМассив А\n";
	ShowArray(A, N1);

	int maxElementIndex_A = GetFirstMaxElementIndex(A, N1);
	cout << "\nИндекс первого max элемента: " << maxElementIndex_A << "\n";

	SetRandomArray(B, N2);
	cout << "\nМассив B\n";
	ShowArray(B, N2);

	int maxElementIndex_B = GetFirstMaxElementIndex(B, N2);
	cout << "\nИндекс первого max элемента: " << maxElementIndex_B << "\n";

	if (maxElementIndex_A < maxElementIndex_B) {
		cout << "\nМаксимум в массиве А ближе к началу";
	}
	else if (maxElementIndex_A > maxElementIndex_B) {
		cout << "\nМаксимум в массиве B ближе к началу";
	}
	else {
		cout << "\nМаксимумы равноудалены от начала массивов";
	}

}