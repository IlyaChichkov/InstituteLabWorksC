#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>

#include <Windows.h> // console

using namespace std;

HANDLE hConsole1 = GetStdHandle(STD_OUTPUT_HANDLE);
#include "DeposidManage.h"

using namespace std;

int MainMenu() {
	// Меню Программы
	while (true) {
		int action = 0;
		int minValue = 0;
		SetConsoleTextAttribute(hConsole1, 14);
		cout << setfill(' ') << setw(2) << right << " " << setw(40) << left << "Меню" << endl;
		SetConsoleTextAttribute(hConsole1, 10);
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "Добавить нового клиента" << setfill('.') << setw(5) << right << 1 << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "Посмотреть список клиентов" << setfill('.') << setw(5) << right << 2 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "Счета большие чем заданное значение" << setfill('.') << setw(5) << right << 3 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "Найти все счета пользователя" << setfill('.') << setw(5) << right << 4 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "Добавить тестовых клиетов" << setfill('.') << setw(5) << right << 5 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "Экспорт данных" << setfill('.') << setw(5) << right << 6 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "Выйти" << setfill('.') << setw(5) << right << 7 << setfill(' ') << endl;
		SetConsoleTextAttribute(hConsole1, 7);
		cout << ">";
		cin >> action;
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');

		switch (action) {
		case 1:
			AddNewClient();
			break;
		case 2:
			ShowAllClientsList();
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
		case 7:
			return 0;
			break;
		}
	}
}

int main() {
	srand(time(NULL));
	setlocale(0, "Russian");

	LoadData();
	MainMenu();
	ApplicationExit();
	return 0;
}