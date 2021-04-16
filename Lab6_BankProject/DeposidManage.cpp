#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <limits>
#include <string.h>

using namespace std;

// ��������� ��������
typedef struct deposid {
	int id;
	char* surname;
	char* name;
	double amount;
} deposid;

int clientsCount = 0;
// ������ ��������
deposid* clients = (deposid*)malloc(0 * sizeof(deposid));

void CreateStandartClients() {
	// ��������� �������� �������
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

		cout << "���������� ������ �������" << endl;
		cout << "������� ���:";
		gets_s(buf); // ���� � �����
		newClient.name = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // ������������ ������ ��� ����������
		strcpy(newClient.name, buf); // ����������� ������ � ������� ���������
		newClient.name[(strlen(buf) + 1)] = '\0';

		cout << "������� �������:";
		gets_s(buf); // ���� � �����
		newClient.surname = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // ������������ ������ ��� ����������
		strcpy(newClient.surname, buf); // ����������� ������ � ������� ���������
		newClient.surname[(strlen(buf) + 1)] = '\0';

		cout << "������� ��������� ���� �� ��������:";
		cin >> newClient.amount;
		// ������� ����������� ������ ��� ��������
		cout << endl << "����� ������������" << endl;
		cout << fixed;
		cout << setprecision(2);
		cout << setw(13) << left << "����� �����:" << setw(15) << right << newClient.id << endl;
		cout << setw(13) << left << "���:" << setw(15) << right << newClient.name << endl;
		cout << setw(13) << left << "�������:" << setw(15) << right << newClient.surname << endl;
		cout << setw(13) << left << "����:" << setw(15) << right << newClient.amount << endl;
		cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
		// ������������� ��������
		bool gotAns = false;
		while (!gotAns) {
			int ans = 0;
			cout << endl;
			cout << setfill(' ') << setw(30) << left << "�����������" << setfill('.') << setw(8) << right << 1 << endl;
			cout << setfill(' ') << setw(30) << left << "����������� � �������� ���" << setfill('.') << setw(8) << right << 2 << endl;
			cout << setfill(' ') << setw(30) << left << "������ ������" << setfill('.') << setw(8) << right << 3 << endl;
			cout << setfill(' ') << setw(30) << left << "�����" << setfill('.') << setw(8) << right << 4 << endl;
			cin >> ans; 
			cin.clear(); // �� ������, ���� ���������� ���� ���������� � �������
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			switch (ans) {
			case 1: // ��������� �������
				gotAns = true;
				addFinished = true;
				clientsCount++;

				clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
				clients[clientsCount - 1] = newClient;
				cout << endl;
				break;
			case 2: // ��������� �������
				gotAns = true;
				addFinished = true;
				clientsCount++;

				clients = (deposid*)realloc(clients, clientsCount * sizeof(deposid));
				clients[clientsCount - 1] = newClient;
				cout << endl;
				AddNewClient();
				break;
			case 3: // ������ �����
				gotAns = true;
				break;
			case 4: // �����
				gotAns = true;
				addFinished = true;
				break;
			}
		}

	}
}

void WriteDataToFile() {
	// ��������/�������� ����� "examples.txt"
	// ����� ���� ������������ ����� fopen
	char buf[256];
	char* fileName = NULL;

	cout << "������� ��� �����:";
	gets_s(buf); // ���� � �����
	fileName = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // ������������ ������ ��� ����������
	strcpy(fileName, buf); // ����������� ������ � ������� ���������
	fileName[(strlen(buf) + 1)] = '\0';

	FILE* file = fopen(strcat(fileName, ".txt"), "w");
	fprintf(file, "������� ������ ��������\n");
	fprintf(file, "� ����� �����  ���   �������  ����\n");
	// ��������� ������
	int listCount = 1;
	for (int i = 0; i < clientsCount; i++) {
		char data[256];
		sprintf(data, "%d %d %s %s %f %s", listCount, clients[i].id, clients[i].name, clients[i].surname, clients[i].amount, "\n");
		listCount++;
		fprintf(file, data);
	}
	// ��������� ����
	fclose(file);
}

void ShowClientsList() {
	// ����� ������� ��������
	cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
	cout << setw(6) << "�" << setw(10) << "����" << setw(15) << "���" << setw(15) << "�������" << setw(15) << "����" << endl;
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
	// ����� ������� ��������
	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
	cout << setw(6) << "�" << setw(10) << "����" << setw(15) << "���" << setw(15) << "�������" << setw(15) << "����" << endl;
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
	cout << setw(6) << "�" << setw(10) << "����" << setw(15) << "���" << setw(15) << "�������" << setw(15) << "����" << endl;
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
	// ����� ������ �� ����� � �������
	char buf[256];
	char* name = NULL;
	char* surname = NULL;

	cout << "���������� ������ �������" << endl;
	cout << "������� ���:";
	gets_s(buf); // ���� � �����
	cout << endl;
	name = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // ������������ ������ ��� ����������
	strcpy(name, buf);

	cout << "������� �������:";
	gets_s(buf); // ���� � �����
	cout << endl;
	surname = (char*)malloc((strlen(buf) + 1) * sizeof(char)); // ������������ ������ ��� ����������
	strcpy(surname, buf);

	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
	cout << setw(6) << "�" << setw(15) << "����" << setw(15) << "���" << setw(15) << "�������" << setw(15) << "����" << endl;
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