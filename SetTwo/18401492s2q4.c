/*
 Name: Daniel Gallagher
 Student ID: 18401492
 
 Set: 2
 Question: 4
 */

#include <stdio.h>

int gcd(int x, int y);

int main(int argc, const char * argv[]) {
    
    //Variable Initialisation
    int a,b;
    
    //User Input: Two Integers
    printf("Input 2 Numbers\n");
    scanf("%d %d", &a, &b);
    
    //Run Recursive Function
    int common_divisor = gcd(a,b);
    
    //Print Output
    printf("Greatest Common Divisor: %d", common_divisor);
}

int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x%y);
    }
    
}

