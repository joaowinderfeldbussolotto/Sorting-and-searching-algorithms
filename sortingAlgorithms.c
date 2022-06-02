#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10
#define MAX 1000

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

void insertionSort(int *v, int len)
{
    int i, j, min_index;
    for (i = 0; i < len - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < len; j++)
        {
            if (v[j] < v[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(i, min_index, v);
        }
    }
}

int partition(int *v, int low, int high)
{
    int pivot_index = high;
    int k = low;
    int i;
    for (i = low; i < high; i++)
    {
        if (v[i] <= v[pivot_index])
        {
            swap(i, k, v);
            k++;
        }
    }
    if (v[k] > v[pivot_index])
    {
        swap(k, pivot_index, v);
        return k;
    }
    return pivot_index;
}

void quickSort(int *v, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(v, low, high);
        // printf("pivot_index = %d", pivot_index);
        quickSort(v, low, pivot_index - 1);
        quickSort(v, pivot_index + 1, high);
    }
}
void quickSortStart(int *v, int lenght)
{
    quickSort(v, 0, lenght - 1);
}


void toggle(int *v, int start, int mid, int end){
    int size = end - start + 1;
    int *aux = (int*)malloc(sizeof(int) * size);
    int i = start;
    int j = mid+1;
    int k = 0;
    while(i <= mid && j <=end){
        if(v[i]<= v[j]){
            aux[k] = v[i];
            i++;
        }
        else{
            aux[k] = v[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        aux[k] = v[i];
        k++;
        i++;
    }

    while(j <= end){
        aux[k] = v[j];
        k++;
        j++;
    }

    for(k = start; k <= end; k++){
       v[k]= aux[k-start];
    }
    free(aux);
}
void mergeSort(int *v, int start, int end){
    if(start < end){
        int mid = (start+end)/2;
        mergeSort(v, start, mid);
        mergeSort(v, mid+1, end);
        toggle(v, start, mid, end);
    }
}
void mergeSortStart(int *v, int lenght){
    mergeSort(v, 0, lenght-1);
}

int getLenghtFromTerminal(int argc, char *argv[]){
    if (argc > 1)
    {
        char *charNum = argv[1];
         return atoi(*(argv + 1));
    }
    else
    {
        return LEN;
    }
}

int main(int argc, char *argv[])
{
    int lenght = getLenghtFromTerminal(argc, argv);
    

    int *v = generateRandomArray(lenght);

    printf("----------RAW ARRAY----------\n");
    printArray(v, lenght);
    mergeSortStart(v, lenght);

    // bubbleSort(v, lenght);
    // selectionSort(v, lenght);
    //insertionSort(v, lenght);
    //quickSortStart(v, lenght);
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
