/*
 
 Daniel Gallagher
 18401492
 
 Set 7
 Question 1
 
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN_TWO(A, B) ( (A) < (B)? A : B) 

#define MIN_FOUR(A, B, C, D) ( (MIN_TWO(A, B)) < (MIN_TWO(C,D)) ? MIN_TWO(A,B) : MIN_TWO(C,D) )

int main(int argc, char** argv) {
    
    int a,b,c,d;
    
    //Program for two integers
    printf("ENTER TWO INTEGERS TO FIND THE MINIMUM: \n");
    scanf("%d%d", &a, &b);
    
    int min_two = MIN_TWO(a,b);
    
    printf("MIN: %d\n\n", min_two);
    
    
    //Program for four integers
    printf("ENTER FOUR INTEGERS TO FIND THE MINUMUM: \n");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    
    int min_four = MIN_FOUR(a,b,c,d);
    
    printf("MIN: %d", min_four);
    
    
}

