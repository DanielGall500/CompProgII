#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

int main(int argc, char** argv) {
    
    //Initialise Array And Pointer
    int arr[ARR_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int *arr_ptr;
    
    arr_ptr = &arr[0];
    
    //Multiply Each Element By Ten
    for(int i = 0; i < ARR_SIZE; i++)
    {
        *arr_ptr++ *= 10; //POINTER ARITHMETIC
    }
    
    //Print Array
    for(int i = 0; i < ARR_SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
}

