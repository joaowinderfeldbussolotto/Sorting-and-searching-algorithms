#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define LEN 1000
#define MAX 100

int* generateRandomArray(){
    int *v = (int*) malloc(LEN * sizeof(int));
    int i =0;
    srand(time(NULL));

    for(;i< LEN; i++){
        *(v+i) = rand() % MAX;
    }
    
    return v;
}

void printArray(int *v, int len){
    int i = 0;
    printf("[");
    for(;i < len; i++){
        printf("%d, ", *(v+i));
    }
        printf("]\n");

}

void swap(int i, int j, int *v){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void bubbleSort(int *v){
    int i, j, aux;
    int isInOrder = 1;
    for(i = LEN -1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(v[j] > v[j+1]){
                isInOrder = 0;
                swap(j, j+1, v);
            }
        }
        if(isInOrder){
            return;
        }
    }
}


int main (){

    int *v = generateRandomArray();
    printf("----------NAO ORDENADO----------\n");
    printArray(v, LEN);
    bubbleSort(v);
        printf("---------- ORDENADO----------\n");

    printArray(v,LEN);

    return 0;
}
