#pragma once

// Фамилия Имя
typedef struct fio {
	char* surname;
	char* name;
} fio;

// Дата
typedef struct date {
	int day;
	char* month;
	int year;
} regDate;

typedef struct deposid {
	int id;
	char* surname;
	char* name;
	double amount;
} deposid;
void AddNewClient();
void ShowAllClientsList();
void ShowClientsListMoreMoneyThen(int minValue);
void SearchClientsDeposits();
void CreateStandartClients();
void WriteDataToFile();
void ApplicationExit();
int LoadData();
void SaveData();
void CheckSavedData();
void ApplicationOpen();
void FindClientRegLater();