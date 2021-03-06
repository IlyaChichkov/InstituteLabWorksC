
#include "stdio.h"
#include <iostream>
#include <iomanip>
#include <clocale>
#include <time.h>

using namespace std;

void Exercise2() // ??????? ?2
{
    const int N = 8; // ?????? ???????

    double squareArray[N][N]; // ??????
    srand(time(NULL)); // ????????????

    // ???????? ??????? ????????? ????????
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            squareArray[i][j] = rand() % 10;
        }
    }

    // ?????? ??????? 
    cout << "?????? (?? ????????? 8*8):\n";
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
    // ????? ????????? 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j < i) {
                sum += squareArray[i][j];
            }
        }
    }
    cout << fixed << setprecision(0) << "\n" << "????? ????????? ??????????? ???????: " << sum << "\n";

    // b)
    const int arraySumLength = (int)(N / 2);
    double arraySumColumns[arraySumLength];
    int arraySumWriteId = 0;
    // ????? ????????? 
    for (int i = 0; i < N; i++)
    {
        int columnSum = 0;
        if (i % 2 != 0) { // ???? ??????? ????????
            for (int j = 0; j < N; j++)
            {
                columnSum += squareArray[j][i]; // ??????? ?????

                // ????????? ? ?????? ????? ?????? ???????
                if (j + 1 == N) {
                    arraySumColumns[arraySumWriteId] = (double)columnSum;
                    arraySumWriteId++;
                }
            }
        }
    }

    cout << "?????? ???? ????????? ???????? ????????: " << "\n";
    for (int j = 0; j < (int)(N / 2); j++) {
        cout << "\t" << arraySumColumns[j];
    }
}
