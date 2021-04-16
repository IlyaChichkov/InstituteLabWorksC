#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>

#include <Windows.h> // console

using namespace std;

HANDLE hConsole1 = GetStdHandle(STD_OUTPUT_HANDLE);
#include "DeposidManage.h"

using namespace std;

int main() {
	srand(time(NULL));
	setlocale(0, "Russian");

	while (true) {
		int action = 0;
		int minValue = 0;
		SetConsoleTextAttribute(hConsole1, 14);
		cout << setfill(' ') << setw(40) << left << "Меню" << endl;
		SetConsoleTextAttribute(hConsole1, 7);
		cout << setfill(' ') << setw(40) << left << "Добавить нового клиента" << setfill('.') << setw(10) << right << 1 << endl;
		cout << setfill(' ') << setw(40) << left << "Посмотреть список клиентов" << setfill('.') << setw(10) << right << 2 << setfill(' ') << endl;
		cout << setfill(' ') << setw(40) << left << "Счета большие чем заданное значение" << setfill('.') << setw(10) << right << 3 << setfill(' ') << endl;
		cout << setfill(' ') << setw(40) << left << "Найти все счета пользователя" << setfill('.') << setw(10) << right << 4 << setfill(' ') << endl;
		cout << setfill(' ') << setw(40) << left << "Добавить тестовых клиетов" << setfill('.') << setw(10) << right << 5 << setfill(' ') << endl;
		cout << setfill(' ') << setw(40) << left << "Экспорт данных" << setfill('.') << setw(10) << right << 6 << setfill(' ') << endl;
		cin >> action;
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');

		switch (action) {
		case 1:
			AddNewClient();
			break;
		case 2:
			ShowClientsList();
			break;
		case 3:
			cout << "Вывести счета, значение которых превышает:" << endl;
			cin >> minValue;
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');

			ShowClientsListMoreMoneyThen(minValue);
			break;
		case 4:
			SearchClientsDeposits();
			break;
		case 5:
			cout << "Добавлены тестовые клиенты" << endl;
			CreateStandartClients();
			break;
		case 6:
			cout << "Экспорт данных" << endl;
			WriteDataToFile();
			break;
		}
	}
	return 0;
}