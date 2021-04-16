#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#define N 10

using namespace std;

char** read_string(int& count) {
	char** tmp;
	char** text = (char**)malloc(count * sizeof(char*));
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

char** read_string123(int& count) {
	char** tmp;
	char** text = (char**)malloc(0 * sizeof(char*));
	char buf[256];


	while (true) {
		printf("\nEnter string:\n");
		char newString[256];
		char* stringP = gets_s(newString);

		if (strcmp(stringP, "end") == 0) {
			break;
		}

		/*
		cout << "-" << *stringP << "-" << endl;
		cout << "-" << stringP << "-" << endl;
		cout << "-" << &stringP << "-" << endl;
		*/
		count++;
		//text = (char*)realloc(text, count * sizeof(int));
	}
	return text;
}

void Exercise1() {
	char** tmp;
	int count = 1;
	char** text = (char**)malloc(sizeof(char*) * count);
	text = read_string(count);

	int i;
	for (i = 0; i < count; i++) {
		free(text[i]);
	}
	free(text);
}
/*
void Exercise12() {
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
	printf("%d",&dinamic_array[1]);
	
	printf("\nARRAY:\n");
	for (i = 0; i < n; i++)
	{
		printf("%s", dinamic_array[i]);
	}

	free(dinamic_array);
}
*/