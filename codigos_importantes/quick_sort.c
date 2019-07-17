#include <stdio.h>

void swap (int *n1, int *n2)
{
    int aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}

int partition(int *array, int start, int end)
{
    int pivot = array[end], i, aux;
    int partitionIndex = start;//setting partition index as start initially
    for(i=start;i<end;i+=1) { //moving the index while we compare the elements that are smaller than the pivot
        if(array[i] <= pivot) {
            if(array[i] < array[partitionIndex]) //swapping, if the comparison is true
                swap(&array[partitionIndex],&array[i]);
            partitionIndex += 1;
        }
    }
    swap(&array[end],&array[partitionIndex]);
    return partitionIndex;
}

void quick_sort (int *array, int start, int end) //remember always to pass as an argument, the array_size - 1
{
    if(start < end) {
        int partitionIndex = partition(array,start,end);
    quick_sort(array,start,partitionIndex-1);//sorting the elements of the left partition index
    quick_sort(array,partitionIndex+1,end);//sorting the elements of the right partition index
}
}

int main(){
    int i;
    int array[] = { 10, 5, 7, 1, 0, 8, 9};
    quick_sort(array,0,6);
    for(i = 0; i < 7; i++){
        printf("%d ",array[i]);
    }
}