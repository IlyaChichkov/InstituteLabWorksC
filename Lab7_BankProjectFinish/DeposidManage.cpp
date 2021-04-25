#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <limits>
#include <string.h>

using namespace std;

void AddNewClient();
void ShowClientsList(struct deposid*, int, bool);
void AddClientToList(deposid);
void CreateStandartClients();
int LoadData();
void SaveData();

typedef struct fio {
	char* surname;
	char* name;
} fio;

typedef struct date {
	int day;
	char* month;
	int year;
} date;

// Структура Депозита
typedef struct deposid {
	int id;
	fio userFIO;
	date registerDate;
	double amount;
} deposid;

// Количество Клиентов В Массиве
int clientsCount = 0;
// Массив Клиентов
deposid* clients = (deposid*)malloc(0 * sizeof(deposid));

char saveName[] = { "data.txt" };

int FileExist(const char* fname)
{
	FILE* file = fopen(fname, "r");

	if (file == NULL) {

		return 0;
	}
	fclose(file);
	return 1;
}

void DataFileExist()
{
	if (FileExist(saveName) == 1) { // если мы нашли данные
		cout << "da";
		LoadData();
	}
	else {
		bool gotAns = false;
		while (!gotAns) {
			int ans = 0;
			cout << ">Файл сохранения не найден" << endl;
			cout << setfill(' ') << setw(30) << left << "Добавить Клиента В Ручную" << setfill('.') << setw(8) << right << 1 << endl;
			cout << setfill(' ') << setw(30) << left << "Добавить Тестовых Клиентов" << setfill('.') << setw(8) << right << 2 << endl;
			cin >> ans;
			cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			switch (ans)
			{
			case 1:
				gotAns = true;
				AddNewClient();
				break;
			case 2:
				gotAns = true;
				CreateStandartClients();
				break;
			}
		}
	}
}

int LoadData() {
	char symbol = ' ';
	int dataLine = 0;
	int dataWord = 0;
	FILE* file = fopen(saveName, "r");

	if (file == NULL) {

		return 0;
	}

	do
	{
		symbol = fgetc(file);
		if (symbol == ';') {
			dataLine++;
			dataWord = 0;
		}
		if (dataLine > 0) {
			
			if (symbol == '_') {
				dataWord++;
			}
			else {
				switch (dataWord)
				{
				case 0:
					break;
				case 1:
					break;
				}
			}
		}

	} while (symbol != EOF); // пока не конец файла
	cout << dataLine;
	fclose(file);
	return 1;
}

void SaveData() {

	FILE* file = fopen(saveName, "w");
	fprintf(file, "Экспорт данных клиентов\n");
	fprintf(file, "№ Номер счета  Имя   Фамилия  Счет\n");
	// Помещение данных
	int listCount = 1;
	for (int i = 0; i < clientsCount; i++) {
		char data[256];
		sprintf(data, "%d_%d_%s_%s_%f_%d_%s_%d;%s", listCount, clients[i].id, clients[i].userFIO.name, clients[i].userFIO.surname, clients[i].amount, clients[i].registerDate.day, clients[i].registerDate.month, clients[i].registerDate.year, "\n");
		listCount++;
		fprintf(file, data);
	}
	// Закрываем файл
	fclose(file);
}

void ShowClientsList(struct deposid* clientsList, int listCount, bool freeListAfterUse = true) {
	// вывод таблицы клиентов
	int tableWidth = 81;
	cout << setfill('-') << setw(tableWidth) << "-" << setfill(' ') << endl;
	cout << setw(6) << "№" << setw(10) << "Индекс" << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(15) << "Счет" << setw(15) << "Дата" << endl;
	cout << setfill('-') << setw(tableWidth) << "-" << setfill(' ') << endl;
	int clientNum = 1;
	cout << fixed;
	cout << setprecision(2);
	for (int i = 0; i < listCount; i++) {
		char date[20];
		sprintf(date, "%d %s %d", clientsList[i].registerDate.day, clientsList[i].registerDate.month, clientsList[i].registerDate.year);
		cout << setw(6) << clientNum << setw(10) << clientsList[i].id << setw(15) << clientsList[i].userFIO.name << setw(15) << clientsList[i].userFIO.surname << setw(15) << clientsList[i].amount << setw(20) << date << endl;
		clientNum++;
	}
	cout << setfill('-') << setw(tableWidth) << "-" << setfill(' ') << endl;
	if (freeListAfterUse) { // если список клиентов временный, чистим память
		free(clientsList);
	}
}

void CreateStandartClients() {
	// добавляем тестовых клиетов
	//1
	deposid newClient = { 4616001, NULL, NULL, 8200 };
	newClient.amount = 8200;
	newClient.userFIO.name = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.userFIO.name, "Tomb");
	newClient.userFIO.name[5] = '\0';

	newClient.userFIO.surname = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.userFIO.surname, "Rine");
	newClient.userFIO.surname[5] = '\0';

	date regDate = { 4, NULL, 2013 };
	regDate.month = (char*)malloc(6 * sizeof(char));
	strcpy(regDate.month, "April");
	regDate.month[6] = '\0';
	newClient.registerDate = regDate;

	clientsCount++;
	clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
	clients[clientsCount - 1] = newClient;
	//2
	newClient = { 7545002, NULL, NULL, 10400 };
	newClient.amount = 10400;
	newClient.userFIO.name = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.userFIO.name, "Rimm");
	newClient.userFIO.name[5] = '\0';

	newClient.userFIO.surname = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.userFIO.surname, "Dove");
	newClient.userFIO.surname[5] = '\0';

	regDate = { 8, NULL, 2013 };
	regDate.month = (char*)malloc(6 * sizeof(char));
	strcpy(regDate.month, "April");
	regDate.month[6] = '\0';
	newClient.registerDate = regDate;

	clientsCount++;
	clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
	clients[clientsCount - 1] = newClient;
	//3
	newClient = { 4986003, NULL, NULL, 12000 };
	newClient.amount = 12000;
	newClient.userFIO.name = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.userFIO.name, "Bill");
	newClient.userFIO.name[5] = '\0';

	newClient.userFIO.surname = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.userFIO.surname, "Dous");
	newClient.userFIO.surname[5] = '\0';

	regDate = { 4, NULL, 2013 };
	regDate.month = (char*)malloc(5 * sizeof(char));
	strcpy(regDate.month, "June");
	regDate.month[5] = '\0';
	newClient.registerDate = regDate;

	clientsCount++;
	clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
	clients[clientsCount - 1] = newClient;
	//4
	newClient = { 6478004, NULL, NULL, 4350 };
	newClient.amount = 4350;
	newClient.userFIO.name = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.userFIO.name, "Tomb");
	newClient.userFIO.name[5] = '\0';

	newClient.userFIO.surname = (char*)malloc(5 * sizeof(char));
	strcpy(newClient.userFIO.surname, "Rine");
	newClient.userFIO.surname[5] = '\0';

	regDate = { 1, NULL, 2018 };
	regDate.month = (char*)malloc(6 * sizeof(char));
	strcpy(regDate.month, "April");
	regDate.month[6] = '\0';
	newClient.registerDate = regDate;

	clientsCount++;
	clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
	clients[clientsCount - 1] = newClient;

}

void ApplicationExit() { // при закрытии программы
	SaveData();
	free(clients); // освобождаем память
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
		newClient.userFIO.name = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // освобождение памяти для переменной
		strcpy(newClient.userFIO.name, buf); // копирование данных в элемент структуры
		newClient.userFIO.name[(strlen(buf) + 1)] = '\0';

		cout << "Введите фамилию:";
		gets_s(buf); // Ввод в буфер
		newClient.userFIO.surname = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // освобождение памяти для переменной
		strcpy(newClient.userFIO.surname, buf); // копирование данных в элемент структуры
		newClient.userFIO.surname[(strlen(buf) + 1)] = '\0';

		cout << "Введите начальный счет на депозите:";
		cin >> newClient.amount;

		cout << "Введите дату создания депозита" << endl;

		do {
			cout << "День: ";
			cin >> newClient.registerDate.day;
		} while (newClient.registerDate.day < 1 || newClient.registerDate.day > 31);

		int month = 0;
		do {
			cout << "Месяц: ";
			cin >> month;
		} while (month < 1 || month > 12);
		
		// преобразовываем месяц в текстовый формат
		switch (month)
		{
		case 1: {
			char monthText[] = { "January" };
			cout << (strlen(monthText) + 1);
			newClient.registerDate.month = (char*)malloc((strlen(monthText)+2) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			  break;
		case 2: {
			char monthText[] = { "February" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			  break;
		case 3: {
			char monthText[] = { "March" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			  break;
		case 4: {
			char monthText[] = { "April" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			break;
		case 5: {
			char monthText[] = { "May" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			  break;
		case 6: {
			char monthText[] = { "June" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			  break;
		case 7: {
			char monthText[] = { "July" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			  break;
		case 8: {
			char monthText[] = { "August" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			  break;
		case 9: {
			char monthText[] = { "September" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			  break;
		case 10: {
			char monthText[] = { "October" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			   break;
		case 11: {
			char monthText[] = { "November" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			   break;
		case 12: {
			char monthText[] = { "December" };
			newClient.registerDate.month = (char*)malloc((strlen(monthText) + 1) * sizeof(char));
			strcpy(newClient.registerDate.month, monthText);
			newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		}
			   break;
		}
		
		do {
			cout << "Год: ";
			cin >> newClient.registerDate.year;
		} while (newClient.registerDate.year < 2000 || newClient.registerDate.year > 2022);
		cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// выводим заполненные данные для проверки
		char date[20];
		sprintf(date, "%d %s %d", newClient.registerDate.day, newClient.registerDate.month, newClient.registerDate.year);

		cout << endl << "Новый пользователь" << endl;
		cout << fixed;
		cout << setprecision(2);
		cout << setfill(' ') << setw(13) << left << "Номер счета:" << setw(15) << right << newClient.id << endl;
		cout << setw(13) << left << "Имя:" << setw(15) << right << newClient.userFIO.name << endl;
		cout << setw(13) << left << "Фамилия:" << setw(15) << right << newClient.userFIO.surname << endl;
		cout << setw(13) << left << "Счет:" << setw(15) << right << newClient.amount << endl;
		cout << setw(13) << left << "Дата:" << setw(15) << right << date << endl;
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
				AddClientToList(newClient);
				cout << endl;
				break;
			case 2: // Добавляем Клиента И Продолжаем Добавлять Нового
				gotAns = true;
				addFinished = true;
				AddClientToList(newClient);
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

void AddClientToList(deposid client) {
	clientsCount++;
	clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
	clients[clientsCount - 1] = client;
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
		sprintf(data, "%d %d %s %s %f %s", listCount, clients[i].id, clients[i].userFIO.name, clients[i].userFIO.surname, clients[i].amount, "\n");
		listCount++;
		fprintf(file, data);
	}
	// Закрываем файл
	fclose(file);
}

void ShowAllClientsList() {
	ShowClientsList(clients, clientsCount, false);
}

void ShowClientsListMoreMoneyThen(int minValue) {
	int listCount = 0;
	deposid* clientsList = (deposid*)malloc(listCount * sizeof(deposid));
	for (int i = 0; i < clientsCount; i++) {
		if (clients[i].amount < minValue) {
			continue;
		}
		listCount++;
		clientsList = (deposid*)realloc(clientsList, listCount * sizeof(deposid));
		clientsList[listCount - 1] = clients[i];
	}
	ShowClientsList(clientsList, listCount);
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

	int listCount = 0;
	deposid* clientsList = (deposid*)malloc(listCount * sizeof(deposid));
	for (int i = 0; i < clientsCount; i++) {
		if (strcmp(clients[i].userFIO.name, name) == 0 && strcmp(clients[i].userFIO.surname, surname) == 0) {
			listCount++;
			clientsList = (deposid*)realloc(clientsList, listCount * sizeof(deposid));
			clientsList[listCount - 1] = clients[i];
		}
	}
	ShowClientsList(clientsList, listCount);
}