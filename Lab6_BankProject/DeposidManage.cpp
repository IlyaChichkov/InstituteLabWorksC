#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <limits>
#include <string.h>

using namespace std;

// Структура Депозита
typedef struct deposid {
	int id;
	char* surname;
	char* name;
	double amount;
} deposid;

int clientsCount = 0;
// Массив Клиентов
deposid* clients = (deposid*)malloc(0 * sizeof(deposid));

void CreateStandartClients() {
	// добавляем тестовых клиетов
	//1
	deposid newClient = { 4616001, NULL, NULL, 8200 };
	newClient.name = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.name, "Tomb");
	newClient.name[5] = '\0';

	newClient.surname = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.surname, "Rine");
	newClient.surname[5] = '\0';

	clientsCount++;
	clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
	clients[clientsCount - 1] = newClient;
	//2
	newClient = { 7545002, NULL, NULL, 10400 };
	newClient.name = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.name, "Rimm");
	newClient.name[5] = '\0';

	newClient.surname = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.surname, "Dove");
	newClient.surname[5] = '\0';

	clientsCount++;
	clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
	clients[clientsCount - 1] = newClient;
	//3
	newClient = { 4986003, NULL, NULL, 12000 };
	newClient.name = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.name, "Bill");
	newClient.name[5] = '\0';

	newClient.surname = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.surname, "Dous");
	newClient.surname[5] = '\0';

	clientsCount++;
	clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
	clients[clientsCount - 1] = newClient;
	//4
	newClient = { 6478004, NULL, NULL, 4350 };
	newClient.name = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.name, "Tomb");
	newClient.name[5] = '\0';

	newClient.surname = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.surname, "Rine");
	newClient.surname[5] = '\0';

	clientsCount++;
	clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
	clients[clientsCount - 1] = newClient;
}

void AddNewClient() {
	bool addFinished = false;
	while (!addFinished) {
		char buf[256];
		deposid newClient = { 0, NULL, NULL, 0 };
		newClient.id = clientsCount + 1 + ((rand() % 9000) * 1000);

		cout << "Добавление нового клиента" << endl;
		cout << "Введите имя:";
		gets_s(buf); // Ввод в буфер
		newClient.name = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // освобождение памяти для переменной
		strcpy(newClient.name, buf); // копирование данных в элемент структуры
		newClient.name[(strlen(buf) + 1)] = '\0';

		cout << "Введите фамилию:";
		gets_s(buf); // Ввод в буфер
		newClient.surname = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // освобождение памяти для переменной
		strcpy(newClient.surname, buf); // копирование данных в элемент структуры
		newClient.surname[(strlen(buf) + 1)] = '\0';

		cout << "Введите начальный счет на депозите:";
		cin >> newClient.amount;
		// выводим заполненные данные для проверки
		cout << endl << "Новый пользователь" << endl;
		cout << fixed;
		cout << setprecision(2);
		cout << setw(13) << left << "Номер счета:" << setw(15) << right << newClient.id << endl;
		cout << setw(13) << left << "Имя:" << setw(15) << right << newClient.name << endl;
		cout << setw(13) << left << "Фамилия:" << setw(15) << right << newClient.surname << endl;
		cout << setw(13) << left << "Счет:" << setw(15) << right << newClient.amount << endl;
		cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
		// подтверждение действия
		bool gotAns = false;
		while (!gotAns) {
			int ans = 0;
			cout << endl;
			cout << setfill(' ') << setw(30) << left << "Подтвердить" << setfill('.') << setw(8) << right << 1 << endl;
			cout << setfill(' ') << setw(30) << left << "Подтвердить и добавить еще" << setfill('.') << setw(8) << right << 2 << endl;
			cout << setfill(' ') << setw(30) << left << "Ввести заново" << setfill('.') << setw(8) << right << 3 << endl;
			cout << setfill(' ') << setw(30) << left << "Назад" << setfill('.') << setw(8) << right << 4 << endl;
			cin >> ans; 
			cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			switch (ans) {
			case 1: // Добавляем Клиента
				gotAns = true;
				addFinished = true;
				clientsCount++;

				clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
				clients[clientsCount - 1] = newClient;
				cout << endl;
				break;
			case 2: // Добавляем Клиента
				gotAns = true;
				addFinished = true;
				clientsCount++;

				clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
				clients[clientsCount - 1] = newClient;
				cout << endl;
				AddNewClient();
				break;
			case 3: // Повтор Ввода
				gotAns = true;
				break;
			case 4: // Назад
				gotAns = true;
				addFinished = true;
				break;
			}
		}

	}
}

void WriteDataToFile() {
	// Создание/открытие файла "examples.txt"
	// Можно было использовать метод fopen
	char buf[256];
	char* fileName = NULL;

	cout << "Введите имя файла:";
	gets_s(buf); // Ввод в буфер
	fileName = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // освобождение памяти для переменной
	strcpy(fileName, buf); // копирование данных в элемент структуры
	fileName[(strlen(buf) + 1)] = '\0';

	FILE* file = fopen(strcat(fileName, ".txt"), "w");
	fprintf(file, "Экспорт данных клиентов\n");
	fprintf(file, "№ Номер счета  Имя   Фамилия  Счет\n");
	// Помещение данных
	int listCount = 1;
	for (int i = 0; i < clientsCount; i++) {
		char data[256];
		sprintf(data, "%d %d %s %s %f %s", listCount, clients[i].id, clients[i].name, clients[i].surname, clients[i].amount, "\n");
		listCount++;
		fprintf(file, data);
	}
	// Закрываем файл
	fclose(file);
}

void ShowClientsList() {
	// вывод таблицы клиентов
	cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
	cout << setw(6) << "№" << setw(10) << "Счет" << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(15) << "Счет" << endl;
	cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
	int listCount = 1;
	for (int i = 0; i < clientsCount; i++) {
		deposid client = { 0, NULL, NULL, 0 };
		client = clients[i];
		cout << fixed;
		cout << setprecision(2);
		cout << setw(6) << listCount << setw(10) << client.id << setw(15) << client.name << setw(15) << client.surname << setw(15) << client.amount << endl;
		listCount++;
	}
	cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
}

void ShowClientsList(deposid* clientsList) {
	// вывод таблицы клиентов
	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
	cout << setw(6) << "№" << setw(10) << "Счет" << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(15) << "Счет" << endl;
	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
	int listCount = 1;
	for (int i = 0; i < clientsCount; i++) {
		deposid client = { 0, NULL, NULL, 0 };
		client = clients[i];
		cout << fixed;
		cout << setprecision(2);
		cout << setw(6) << listCount << setw(10) << client.id << setw(15) << client.name << setw(15) << client.surname << setw(15) << client.amount << endl;
		listCount++;
	}
	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
}

void ShowClientsListMoreMoneyThen(int minValue) {

	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
	cout << setw(6) << "№" << setw(10) << "Счет" << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(15) << "Счет" << endl;
	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
	int listCount = 1;
	for (int i = 0; i < clientsCount; i++) {
		deposid client = { 0, NULL, NULL, 0 };
		client = clients[i];
		if (client.amount < minValue) {
			continue;
		}
		cout << fixed;
		cout << setprecision(2);
		cout << setw(6) << listCount << setw(10) << client.id << setw(15) << client.name << setw(15) << client.surname << setw(15) << client.amount << endl;
		listCount++;
	}
	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
}

void SearchClientsDeposits() {
	// Поиск счетов по имени и фамилии
	char buf[256];
	char* name = NULL;
	char* surname = NULL;

	cout << "Добавление нового клиента" << endl;
	cout << "Введите имя:";
	gets_s(buf); // Ввод в буфер
	cout << endl;
	name = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // освобождение памяти для переменной
	strcpy(name, buf);

	cout << "Введите фамилию:";
	gets_s(buf); // Ввод в буфер
	cout << endl;
	surname = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // освобождение памяти для переменной
	strcpy(surname, buf);

	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
	cout << setw(6) << "№" << setw(15) << "Счет" << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(15) << "Счет" << endl;
	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
	int listCount = 1;
	for (int i = 0; i < clientsCount; i++) {
		if (strcmp(clients[i].name, name) == 0 && strcmp(clients[i].surname, surname) == 0) {
			cout << fixed;
			cout << setprecision(2);
			cout << setw(6) << listCount << setw(15) << clients[i].id << setw(15) << clients[i].name << setw(15) << clients[i].surname << setw(15) << clients[i].amount << endl;
			listCount++;
		}
	}
	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
}