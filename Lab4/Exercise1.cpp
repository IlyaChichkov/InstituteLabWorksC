#include "stdio.h"
#include <iostream>
#include <iomanip>
#include <clocale>
#include <time.h>

#include <Windows.h> // console

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const int N = 8; // ������ ������� (��� ������ �)

int* GetFirstMaxElementIndex(double *arr, int arrLength) { // ������� ������ ������� max ��������
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
	return &maxIndex; // ���������� ���������
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
	const int N1 = 6, N2 = 8; // ������� ������
	double A[N1], B[N2]; // ������� �������

	srand(time(NULL));

	// ����������� ��������� ��������, ���������� � �������
	SetRandomArray(A, N1);
	cout << "\n������ �\n";
	ShowArray(A, N1);

	int* maxElementIndex_A = GetFirstMaxElementIndex(A, N1);
	int Index_A = *maxElementIndex_A;
	cout << "\n������ ������� max ��������: " << Index_A << "\n";
	

	SetRandomArray(B, N2);
	cout << "\n������ B\n";
	ShowArray(B, N2);

	int* maxElementIndex_B = GetFirstMaxElementIndex(B, N2);
	int Index_B = *maxElementIndex_B;

	printf("%s%d%s","\n������ ������� max ��������: ", Index_B, "\n"); 

	//printf("%s%d%s%d","A:",Index_A," compare to B:",Index_B); // DEBUG

	if (Index_A < Index_B) {
		printf("\n�������� � ������� � ����� � ������\n");
	}else
	if (Index_A > Index_B) {
		printf("\n�������� � ������� B ����� � ������\n");
	}
	else{
		printf("\n��������� ������������ �� ������ ��������\n");
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
			// ������� �������
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

int GetFormElementsSum(int arr[][N], int arrLength) { // ����� ��������� � ������� �������
	int sum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		for (int j = 0; j < arrLength; j++)
		{
			// ������� �������
			if (i > j - 1) {
				sum += arr[i][j];
			}
		}
	}
	return sum;
}

void PointB() {
	int arr[N][N];

	printf("\n���� ������������� ������� 8x8. ������� ������� ���  ���������� ����� ��������� � �������������� �������\n");
	// ����������� ��������� ��������, ���������� � �������
	SetRandomMultiArray(arr, N);
	ShowMultiArray(arr, N);
	printf("%d %s",GetFormElementsSum(arr, N), "\n");
}

void Exercise1() {
	
	PointA();
	PointB();
}