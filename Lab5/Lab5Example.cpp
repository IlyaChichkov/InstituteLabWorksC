// Lab5Example.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;
int** create_matrix(int n_row, int n_column) {
	int** ptr = (int**)malloc(n_row * sizeof(int*));
	int i;
	for (i = 0; i < n_column; i++) {
		ptr[i] = (int*)malloc(n_column * sizeof(int));
	}
	return ptr;
}
void init_matric(int** matrix, int n_row, int n_column) {
	int i, j;

	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_row; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
}
void print_matric(int** matrix, int n_row, int n_column) {
	int i, j;

	for (i = 0; i < n_row; i++) {
		for (j = 0; j < n_row; j++) {
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

char** read_string(int& count) {
	char** tmp;
	char** text = (char**)malloc(0 * sizeof(char*));
	char buf[256];

	while (true) {
		fgets(buf, 256, stdin);

		if (strcmp(buf, "end\n") == 0) {
			break;
		}

		tmp = (char**)realloc(text, count + 1 * sizeof(char*));
		if (tmp == NULL) {
			cout << "Memory Error" << endl;
			break;
		}
		else {
			text = tmp;
		}
		text[count] = (char*)malloc(strlen(buf) + 1 * sizeof(char));
		//*(text + count) = (char*)malloc(strlen(buf) + 1 * sizeof(char));
		strcpy(text[count], buf);
		count++;
	}
	int i;
	for (i = 0; i < count; i++) {
		printf("%s", text[i]);
	}
	return text;
}

int main()
{
	char** tmp;
	char** text = (char**)malloc(0 * sizeof(char*));
	int count = 0;
	text = read_string(count);

	int i;
	for (i = 0; i < count; i++) {
		free(text[i]);
	}
	free(text);
	return 0;
}