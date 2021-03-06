#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <limits>
#include <string.h>

using namespace std;

//***инициализация функций***
void AddNewClient();
void ShowClientsList(struct deposid*, int, bool);
void AddClientToList(deposid);
void CreateStandartClients();
int LoadData();
void SaveData();
int GetMonthNumber(char*);
char* GetMonthString(int);
deposid* ListAdd(deposid*, int&, deposid&);
//***инициализация функций***

// Структура Фамилии и Имени
typedef struct fio {
	char* surname;
	char* name;
} fio;

// Структура Даты
typedef struct date {
	int day;
	char* month;
	int year;
} regDate;

// Структура Депозита
typedef struct deposid {
	int id;
	fio userFIO;
	date registerDate;
	double amount;
} deposid;

//(!)// Количество Клиентов В Массиве
int clientsCount = 0;
//(!)// Массив Клиентов
deposid* clients = (deposid*)malloc(0 * sizeof(deposid));

char saveName[] = { "data.txt" }; // файл сохранения

// проверка существования файла
int FileExist(const char* fname)
{
	FILE* file = fopen(fname, "r");

	if (file == NULL) {

		return 0;
	}
	fclose(file);
	return 1;
}

// проверка на файл сохранения
void CheckSavedData()
{
	if (FileExist(saveName) == 1) { // если мы нашли данные
		cout << "Найден файл сохранения" << endl;
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

// Загружаем данные
int LoadData() {
	char buf[255];
	FILE* file = fopen(saveName, "r");

	if (file == NULL) {

		return 0;
	}

	deposid loadClient;
	fio clientFIO;
	regDate registerDate;
	int loadClientsCount = 0;

	while (!feof(file)) {
		loadClient = { 0, { NULL, NULL }, { 1, NULL, 2000 }, 0 };
		fgets(buf, 255, file);
		char *loadData = strtok(buf, "_");
		int dataType = 0;
		while (loadData != NULL)
		{
			switch (dataType)
			{
			case 1: // UID
				loadClient.id = strtol(loadData, NULL, 0);
				//cout << loadClient.id << endl;
				break;
			case 2: // Name
				loadClient.userFIO.name = (char*)malloc((strlen(loadData) + 1) * sizeof(char)); // освобождение памяти для переменной
				strcpy(loadClient.userFIO.name, loadData); // копирование данных в элемент структуры
				loadClient.userFIO.name[(strlen(loadData) + 1)] = '\0';
				//cout << loadClient.userFIO.name << endl;
				break;
			case 3: // Surname
				loadClient.userFIO.surname = (char*)malloc((strlen(loadData) + 1) * sizeof(char)); // освобождение памяти для переменной
				strcpy(loadClient.userFIO.surname, loadData); // копирование данных в элемент структуры
				loadClient.userFIO.surname[(strlen(loadData) + 1)] = '\0';
				//cout << loadClient.userFIO.surname << endl;
				break;
			case 4: // Money
				loadClient.amount = (double)strtol(loadData, NULL, 0);
				//cout << loadClient.amount << endl;
				break;
			case 5: // Day
				loadClient.registerDate.day = (double)strtol(loadData, NULL, 0);
				break;
			case 6: // Month
				loadClient.registerDate.month = (char*)malloc((strlen(loadData) + 1) * sizeof(char)); // освобождение памяти для переменной
				strcpy(loadClient.registerDate.month, loadData); // копирование данных в элемент структуры
				loadClient.registerDate.month[(strlen(loadData) + 1)] = '\0';
				break;
			case 7: // Year
				loadClient.registerDate.year = (double)strtol(loadData, NULL, 0);
				//cout << loadClient.registerDate.year << endl;
				break;
			}

			dataType++;
			loadData = strtok(NULL, "_");
		} // line have read

		if (loadClient.id != 0) {

			AddClientToList(loadClient);
			loadClientsCount++;
		}
	} // file ENDs
	free(loadClient.userFIO.name);
	free(loadClient.userFIO.surname);
	free(loadClient.registerDate.month);
	fclose(file);
	printf_s("%d %s", loadClientsCount, " клиента было загружено...\n");
	return 1;
}

// Сохраняем данные
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

// функция отображающая поступающий список клиентов
void ShowClientsList(struct deposid* clientsList, int listCount, bool freeListAfterUse = true) {

	// вывод таблицы клиентов
	int tableWidth = 81;
	cout << setfill('-') << setw(tableWidth) << "-" << setfill(' ') << endl;
	cout << setw(6) << "№" << setw(10) << "Индекс" << setw(15) << "Имя" << setw(15) << "Фамилия" << setw(15) << "Счет" << setw(15) << "Дата" << endl;
	cout << setfill('-') << setw(tableWidth) << "-" << setfill(' ') << endl;
	int clientNum = 1;
	cout << fixed;
	cout << setprecision(2);
	int i;
	for (i = 0; i < listCount; i++) {
		char registrationDate[50];
		sprintf(registrationDate, "%d %s %d", clientsList[i].registerDate.day, clientsList[i].registerDate.month, clientsList[i].registerDate.year);
		cout << setw(6) << clientNum << setw(10) << clientsList[i].id << setw(15) << clientsList[i].userFIO.name << setw(15) << clientsList[i].userFIO.surname << setw(15) << clientsList[i].amount << setw(20) << registrationDate << endl;
		clientNum++;
	}
	cout << setfill('-') << setw(tableWidth) << "-" << setfill(' ') << endl;
	if (freeListAfterUse) { // если список клиентов временный (не глобальный список), чистим память
		free(clientsList);
	}
}

// добавляем тестовых клиетов
void CreateStandartClients() {
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

	AddClientToList(newClient);
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

	AddClientToList(newClient);
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

	AddClientToList(newClient);
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

	AddClientToList(newClient);

}

// преобразовываем месяц в текстовый формат
char* GetMonthString(char* buf, int month) {
	switch (month)
	{
	case 1: {
		char monthText[] = { "January" };
		strcpy(buf, monthText);
	}
		  break;
	case 2: {
		char monthText[] = { "February" };
		strcpy(buf, monthText);
	}
		  break;
	case 3: {
		char monthText[] = { "March" };
		strcpy(buf, monthText);
	}
		  break;
	case 4: {
		char monthText[] = { "April" };
		strcpy(buf, monthText);
	}
		  break;
	case 5: {
		char monthText[] = { "May" };
		strcpy(buf, monthText);
	}
		  break;
	case 6: {
		char monthText[] = { "June" };
		strcpy(buf, monthText);
	}
		  break;
	case 7: {
		char monthText[] = { "July" };
		strcpy(buf, monthText);
	}
		  break;
	case 8: {
		char monthText[] = { "August" };
		strcpy(buf, monthText);
	}
		  break;
	case 9: {
		char monthText[] = { "September" };
		strcpy(buf, monthText);
	}
		  break;
	case 10: {
		char monthText[] = { "October" };
		strcpy(buf, monthText);
	}
		   break;
	case 11: {
		char monthText[] = { "November" };
		strcpy(buf, monthText);
	}
		   break;
	case 12: {
		char monthText[] = { "December" };
		strcpy(buf, monthText);
	}
		   break;
	}
	return NULL;
}

// добавление нового пользователя
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

		do
		{
			gets_s(buf); // Ввод в буфер
			newClient.amount = strtol(buf, NULL, 0);
		} while (strtol(buf, NULL, 0) == 0);

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
		char monthText[255];
		GetMonthString(monthText, month);
		cout << (strlen(monthText) + 1);
		newClient.registerDate.month = (char*)malloc((strlen(monthText) + 2) * sizeof(char));
		strcpy(newClient.registerDate.month, monthText);
		newClient.registerDate.month[(strlen(monthText) + 1)] = '\0';
		

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

// добавление клиента в базу данных
void AddClientToList(deposid client) {
	clientsCount++;
	clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
	clients[clientsCount - 1] = client;
}

// сохранение в файл (старое)
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

// отображение базы данных
void ShowAllClientsList() {
	ShowClientsList(clients, clientsCount, false);
}

// клиенты со счетом больше чем (...)
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

// поиск по ФИО
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

// удаление данных пользователей
void ClearClients() {
	free(clients);
}

// добавление элемента в произвольный список
deposid* ListAdd(deposid* list, int &listCount, deposid &add) {

	listCount++;
	list = (deposid*)realloc(list, listCount * sizeof(deposid));
	list[listCount - 1] = add;
	return list;
}

// поиск клиента со счетом открытым позже (...)
void FindClientRegLater() {
	char buf[255];
	regDate minRegDate = { 0, NULL, 0 };

	do {
		cout << "День: ";
		cin >> minRegDate.day;
	} while (minRegDate.day < 1 || minRegDate.day > 31);

	int month = 0;
	do {
		cout << "Месяц: ";
		cin >> month;
	} while (month < 1 || month > 12);

	do {
		cout << "Год: ";
		cin >> minRegDate.year;
	} while (minRegDate.year < 2000 || minRegDate.year > 2022);
	cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int clientsListCount = 0;
	deposid* clientsList = (deposid*)malloc(sizeof(deposid) * 0);
	int i = 0;
	for (i; i < clientsCount; i++) {
		// year check
		if (clients[i].registerDate.year > minRegDate.year) {
			clientsList = ListAdd(clientsList, clientsListCount, clients[i]);
		}
		else if (clients[i].registerDate.year == minRegDate.year) {
			// month check
			if (GetMonthNumber(clients[i].registerDate.month) > month) {
				clientsList = ListAdd(clientsList, clientsListCount, clients[i]);
			}
			else if(GetMonthNumber(clients[i].registerDate.month) == month) {
				// day check
				if (clients[i].registerDate.day > minRegDate.day) {
					clientsList = ListAdd(clientsList, clientsListCount, clients[i]);
				}
			}
		}
	}
	ShowClientsList(clientsList, clientsListCount);
}

// форматируем месяц из строки в число
int GetMonthNumber(char* month) {
	if (strcmp(month, "January") == 0) { return 1; }
	if (strcmp(month, "February") == 0) { return 2; }
	if (strcmp(month, "March") == 0) { return 3; }
	if (strcmp(month, "April") == 0) { return 4; }
	if (strcmp(month, "May") == 0) { return 5; }
	if (strcmp(month, "June") == 0) { return 6; }
	if (strcmp(month, "July") == 0) { return 7; }
	if (strcmp(month, "August") == 0) { return 8; }
	if (strcmp(month, "September") == 0) { return 9; }
	if (strcmp(month, "Octouber") == 0) { return 10; }
	if (strcmp(month, "November") == 0) { return 11; }
	if (strcmp(month, "December") == 0) { return 12; }

	return -1;
}

// при открытии программы
void ApplicationOpen() {
	CheckSavedData();
}

// при закрытии программы
void ApplicationExit() {
	SaveData(); // сохраняем данные
	ClearClients(); // освобождаем память
}

/*
for (i; i < clientsCount; i++) {
		cout << endl << "User: " << i << endl;
		if (clients[i].registerDate.year < minRegDate.year) {
			continue;
		}
		cout << "Year: yes " << i << endl;
		if (GetMonthNumber(clients[i].registerDate.month) < month) {
			cout << endl << "User m: " << GetMonthNumber(clients[i].registerDate.month) << "need: " << month << endl;
			continue;
		}
		cout << "Month: yes " << i << endl;
		if (clients[i].registerDate.day <= minRegDate.day) {
			continue;
		}
		cout << "Day: yes " << i << endl;
		clientsListCount++;
		clientsList = (deposid*)realloc(clientsList, clientsListCount * sizeof(deposid));
		clientsList[clientsListCount - 1] = clients[i];
	}
	ShowClientsList(clientsList, clientsListCount);
*/