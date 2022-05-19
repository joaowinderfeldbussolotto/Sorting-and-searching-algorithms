#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10
#define MAX 100

int *generateRandomArray(int len)
{
    int *v = (int *)malloc(len * sizeof(int));
    int i = 0;
    srand(time(NULL));

    for (; i < len; i++)
    {
        *(v + i) = rand() % MAX;
    }

    return v;
}

void printArray(int *v, int len)
{
    int i = 0;
    printf("[");
    for (; i < len; i++)
    {
        printf("%d, ", *(v + i));
    }
    printf("]\n");
}

void swap(int i, int j, int *v)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void bubbleSort(int *v, int len)
{
    int i, j, aux;
    int isInOrder = 1;
    for (i = len - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                isInOrder = 0;
                swap(j, j + 1, v);
            }
        }
        if (isInOrder)
        {
            return;
        }
    }
}

void selectionSort(int *v, int len)
{
    int i, j, min;
    for (j = 0; j < len - 1; j++)
    {
        min = j;
        for (i = j + 1; i < len; i++)
        {
            if (v[i] < v[min])
            {
                min = i;
            }
        }
        if (min != j)
        {
            swap(j, min, v);
        }
    }
}

int main(int argc, char *argv[])
{
    int lenght;
    if (argc > 1)
    {
        char *charNum = argv[1];
        lenght = atoi(*(argv + 1));
    }
    else
    {
        lenght = LEN;
    }

    int *v = generateRandomArray(lenght);

    printf("----------RAW ARRAY----------\n");
    printArray(v, lenght);
    // bubbleSort(v, lenght);
    selectionSort(v, lenght);
    printf("---------- ORDED----------\n");

    printArray(v, lenght);

    return 0;
}

// to read input
/*
   int *v = (int *)malloc(LEN * sizeof(int));

   scanf(" %d", &lenght);

   for (int i = 0; i < lenght; i++)
   {
       scanf(" %d", &v[i]);
   }
   */
