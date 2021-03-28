#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>


using namespace std;
void Exercise1() {
	int i, n = 1;
	char *dinamic_array;
	dinamic_array = (char*)malloc(n * sizeof(char));

	while (true) {
		printf("\nEnter string:\n");
		char newString[256];
		char* stringP = gets_s(newString);

		if (strcmp(stringP, "end") == 0) {
			break;
		}
		dinamic_array[n] = *stringP;

		cout << "-" << *stringP << "-" << endl;
		cout << "-" << stringP << "-" << endl;
		cout << "-" << &stringP << "-" << endl;
		n++;
		dinamic_array = (char*)realloc(dinamic_array, n * sizeof(int));
	}

	printf("\nARRAY:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d", dinamic_array[i]);
	}

	free(dinamic_array);
}