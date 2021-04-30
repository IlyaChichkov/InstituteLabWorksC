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

	bool onStart = true; // триггер условие начала программы
	// Меню Программы
	while (true) {
		if (onStart) {
			ApplicationOpen(); // при открытии программы
			onStart = false;
		}
		int action = 0;
		int minValue = 0;
		SetConsoleTextAttribute(hConsole1, 14);
		cout << setfill(' ') << setw(2) << right << " " << setw(40) << left << "Меню" << endl;
		SetConsoleTextAttribute(hConsole1, 10);
		int spaceForWords = 50;
		cout << setfill(' ') << setw(2) << right << " " << setw(spaceForWords) << left << "Добавить нового клиента" << setfill('.') << setw(5) << right << 1 << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(spaceForWords) << left << "Посмотреть список клиентов" << setfill('.') << setw(5) << right << 2 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(spaceForWords) << left << "Счета большие чем заданное значение" << setfill('.') << setw(5) << right << 3 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(spaceForWords) << left << "Найти все счета пользователя" << setfill('.') << setw(5) << right << 4 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(spaceForWords) << left << "Добавить тестовых клиетов" << setfill('.') << setw(5) << right << 5 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(spaceForWords) << left << "Экспорт данных" << setfill('.') << setw(5) << right << 6 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(spaceForWords) << left << "Найти пользователей зарегистрированных позже" << setfill('.') << setw(5) << right << 7 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(spaceForWords) << left << "Выйти" << setfill('.') << setw(5) << right << 8 << setfill(' ') << endl;
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
			cout << "Сохранить данных" << endl;
			WriteDataToFile();
			break;
		case 7:

			FindClientRegLater();
			break;
		case 8:
			SetConsoleTextAttribute(hConsole1, 7);
			ApplicationExit();
			return 0;
			break;
		}
	}
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	MainMenu();
	return 0;
}