// DinamicArrayExample.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

int* CreateRandomDinamicArray_INT(int size) {
    int i;
    int* dinamic_array = (int*)malloc(size * sizeof(int));
    
    for (i = 0; i < size; i++)
    {
        dinamic_array[i] = rand() % 201 - 100;
    }
    return dinamic_array;
}

int* ResizeDinamicArray_INT(int* arr, int newSize) {
    int i;
    int* dinamic_array = (int*)realloc(arr, newSize * sizeof(int));
    
    for (i = sizeof(arr); i < newSize; i++)
    {
        dinamic_array[i] = rand() % 201 - 100;
    }
    return dinamic_array;
}

int main()
{
    srand(time(NULL));

    int i, n = 4;
    int newSize = n + 3;
    int* dinamic_array;

    dinamic_array = CreateRandomDinamicArray_INT(n);

    for (i = 0; i < sizeof(dinamic_array); i++)
    {
        dinamic_array[i] = 1;
    }

    // Вывод элементов массива
    printf("Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", dinamic_array[i]);
    }

    dinamic_array = ResizeDinamicArray_INT(dinamic_array, newSize);

    // Вывод элементов массива
    printf("\nNew Array:\n");
    for (i = 0; i < newSize; i++)
    {
        printf("%d ", dinamic_array[i]);
    }

    free(dinamic_array);

    return 0;
}