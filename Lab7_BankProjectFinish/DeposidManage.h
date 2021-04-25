#pragma once
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