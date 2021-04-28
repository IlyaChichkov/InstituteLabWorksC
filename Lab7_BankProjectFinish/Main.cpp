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
	// ���� ���������
	while (true) {
		int action = 0;
		int minValue = 0;
		SetConsoleTextAttribute(hConsole1, 14);
		cout << setfill(' ') << setw(2) << right << " " << setw(40) << left << "����" << endl;
		SetConsoleTextAttribute(hConsole1, 10);
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "�������� ������ �������" << setfill('.') << setw(5) << right << 1 << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "���������� ������ ��������" << setfill('.') << setw(5) << right << 2 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "����� ������� ��� �������� ��������" << setfill('.') << setw(5) << right << 3 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "����� ��� ����� ������������" << setfill('.') << setw(5) << right << 4 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "�������� �������� �������" << setfill('.') << setw(5) << right << 5 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "������� ������" << setfill('.') << setw(5) << right << 6 << setfill(' ') << endl;
		cout << setfill(' ') << setw(2) << right << " " << setw(37) << left << "�����" << setfill('.') << setw(5) << right << 7 << setfill(' ') << endl;
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
			cout << "������� �����, �������� ������� ���������:" << endl;
			cin >> minValue;
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');

			ShowClientsListMoreMoneyThen(minValue);
			break;
		case 4:
			SearchClientsDeposits();
			break;
		case 5:
			cout << "��������� �������� �������" << endl;
			CreateStandartClients();
			break;
		case 6:
			cout << "������� ������" << endl;
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
	setlocale(LC_ALL, "Russian");

	DataFileExist();
	Some();
	MainMenu();
	ApplicationExit();
	return 0;
}