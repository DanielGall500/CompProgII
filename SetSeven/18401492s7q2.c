/*
 
 Daniel Gallagher
 18401492
 
 Set 7
 Question 2
 
*/

#include <stdio.h>
#include <stdlib.h>


#define PRINT_ARRAY(ARR, N)   \
for(int i = 0; i < N; i++)    \
    printf("%d ", ARR[i]);    \
    
#define PRINT_REVERSE_ARRAY(ARR, N)      \
for(int i = N-1; i >= 0; i--)            \
    printf("%d ", ARR[i]);               \


int main(int argc, char** argv) {

    int myArray[5] = {1, 4, 8, 16, 32};
   
    printf("Array: \n");
    PRINT_ARRAY(myArray, 5);
    
    printf("\n\nReversed Array: \n");
    PRINT_REVERSE_ARRAY(myArray, 5);
    
}

