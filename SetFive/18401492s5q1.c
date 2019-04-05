#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE  10

void reverseArray(int arraySize, int a[]);
void randomiseArray(int arraySize, int a[]);
void printArray(int arraySize, int a[], void (*arrayFunction)(int arraySize, int a[]));

int myArray[ARRAY_SIZE] = {2,4,6,8,10,12,14,16,18,20};

int main(int argc, char** argv) {
    
    //User Input
    int input;
    
    printf("Which function would you like to use?\n");
    printf("Enter 0 for reverse, 1 for randomise.\n");
    
    scanf("%d", &input);
    
    //Choosing Which Function To Use
    if (input == 0)
    {
        //Reverse The Array
        printArray(ARRAY_SIZE, myArray, reverseArray);
    }
    else if(input == 1)
    {
        //Randomise The Array
        printArray(ARRAY_SIZE, myArray, randomiseArray);
    }
    else
    {
        printf("Non-Valid Input");
    }
    
}

void reverseArray(int arraySize, int a[])
{   
    //Reverse the array using a temporary
    //variable which holds one of the values
    //to be swapped
    
    for(int i = 0; i < arraySize/2; i++)
    {
        int j = (arraySize-1)-i;
        int temp;
        
        temp = a[i];
        
        a[i] = a[j];
        a[j] = temp;
    }
}

void randomiseArray(int arraySize, int a[])
{
    int temp;
    srand(time(NULL)); 
    
    //start at the beginning and 
    //swap with a random index
    for(int i = 0; i < arraySize; i++)
    {
        //random number between 0 and the last index
        size_t rand_indx = rand() % arraySize;
        
        temp = a[i];
        a[i] = a[rand_indx];
        a[rand_indx] = temp;
    }
}

void printArray(int arraySize, int a[], void (*arrayFunction)(int arraySize, int a[]))
{
    //call the function pointer
    arrayFunction(arraySize, a);
    
    //print out the array
    for(int i = 0; i < arraySize; i++)
    {
        printf("%d ", a[i]);
    }
}

