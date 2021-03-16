#include "stdio.h"
#include <iostream>
#include <iomanip>
#include <clocale>
#include <time.h>

#include <Windows.h> // console

using namespace std;

const int N = 9;

int GetZeroCountInLine(int lineID, double arr[N][N], int length) {
	int count = 0;
	for (int j = 0; j < length; j++)
	{
		if (lineID + j < length && lineID < j + 1) {

			if (arr[lineID][j] == 0) {
				count++;
			}
		}
		else if (lineID + j > length - 2 && lineID > j - 1)
		{
			if (arr[lineID][j] == 0) {
				count++;
			}
		}
	}
	return count;
}

void Exercise2() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	double squareArray[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			squareArray[i][j] = rand() % 100 - 50;
			if (squareArray[i][j] < -35) {
				squareArray[i][j] = 0;
			}
		}
	}
	// show array
	SetConsoleTextAttribute(hConsole, 7);
	for (int i = 0; i < N; i++) 
	{
		cout << endl << i << ":  ";
		for (int j = 0; j < N; j++)
		{
			bool zerovalue = false;
			if (squareArray[i][j] == 0) {
				zerovalue = true;
			}

			if (zerovalue) {
				SetConsoleTextAttribute(hConsole, 14);
			}
			else {
				SetConsoleTextAttribute(hConsole, 12);
			}

			if (i + j < N && i < j + 1) {
				
				cout << setw(6) << setprecision(3) << squareArray[i][j] << ' ';
			}
			else if (i + j > N - 2 && i > j - 1)
			{
				cout << setw(6) << setprecision(3) << squareArray[i][j] << ' ';
			}
			else {
				SetConsoleTextAttribute(hConsole, 7);
				cout << setw(6) << setprecision(3) << squareArray[i][j] << ' ';
			}
			SetConsoleTextAttribute(hConsole, 7);
		}
	}

	cout << endl;
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "Line " << i << " zero count: " << GetZeroCountInLine(i, squareArray, N) << endl;
	}


	cout << "\n";
}