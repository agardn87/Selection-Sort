#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size){
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void swap(int *x, int *y){
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void selectionSort(int array[], int n){
    int min;
    int i;
    int j;
    for(i = 0; i < n; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(min != i)
            swap(&array[i], &array[min]);
    }
    printArray(array, n);
}


int main(int argc, char *argV[]) {
    if(argc < 2){
        printf("Arguments should be: ./main [array size] [list of array elements] \n");
        exit(0);
    }
    if(atoi(argV[1]) != (argc - 2)){
        printf("The list of elements does not match the size entered.\n");
        exit(0);
    }
    int size = argc - 2;
    int i;
    int array[size];
    for(i = 0; i < size; i ++){
        array[i] = atoi(argV[i]);
    }
    selectionSort(array, size);
    return 0;
}