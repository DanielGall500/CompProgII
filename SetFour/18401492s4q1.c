/*
 Name: Daniel Gallagher
 Student ID: 18401492
  
 Set 4
 Question 1
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    
    printf("~SIZE OF TYPES~\n");
    
    /*
      Integer array of size 10 should be
      of size 10 multiplied by the size of 
      the integer
    */
    int int_arr[10];
    
    /*Pointer to an array of size 10*/
    int point_arr[10];
    int *p = point_arr;
    
    /*PRINT EACH SIZE*/
    printf("Size Of Char: %lu\n", sizeof(char));
    
    printf("Size Of Int: %lu\n", sizeof(int));
    
    printf("Size Of Long: %lu\n", sizeof(long));
    
    printf("Size Of Long Long: %lu\n", sizeof(long long));
    
    printf("Size Of Double: %lu\n", sizeof(double));
    
    printf("Size Of Long Double: %lu\n", sizeof(long double));
    
    printf("Size Of Float: %lu\n", sizeof(float));
    
    printf("Size Of Integer Array: %lu\n", sizeof(int_arr));
    
    printf("Size Of A Pointer To An Array: %lu\n", sizeof(p));
    
    
}

