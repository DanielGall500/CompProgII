/*
 18401492s1q1.c
 Set One
 Question One
 
 Student ID: Daniel Gallagher
 Student Number: 18401492
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shortest_func(int a, int b, int c);
int tallest_func(int a, int b, int c);
int average_func(int a, int b, int c);


int main() {
    
    //h1,h2,h3 are our three heights
    int h1,h2,h3;
    int avg, tallest, shortest;
    
    
    //USER INPUT: HEIGHTS
    printf("Input three heights: ");
    scanf("%d%d%d", &h1,&h2,&h3);
    
    //CALCULATE AVERAGE, SHORTEST & TALLEST
    //Three function calls. These
    //functions are explained in detail
    //below
    avg = average_func(h1,h2,h3);
    tallest = tallest_func(h1,h2,h3);
    shortest = shortest_func(h1,h2,h3);
    
    //PRINT OUTPUT
    printf("Average is %d\n", avg);
    printf("Tallest is %d\n", tallest);
    printf("Shortest is %d\n", shortest);
    
}

int shortest_func(int a, int b, int c)
{
    /*
     We initialize our shortest variable
     to the first parameter (a).
     * 
     * We check this against parameter
     * (b) and (c) updating it as we go
     * 
     * This minimizes the amount of statements
     * that we need
     */
    
    int shrt = a;
    
    if(b < a)
    {
        shrt = b;
    }
    
    if(c < b)
    {
        shrt = c;
    }
    
    return shrt;
}

int tallest_func(int a, int b, int c)
{
    /*
     * Similar to the last function,
     * we initialize our tallest variable
     * to the first parameter (a).We then
     * check this against parameter (b) and (c)
     */
    
    int tall = a;
    
    if(b > a)
    {
        tall = b;
    }
    
    if(c > b)
    {
        tall = c;
    }
    
    return tall;
}

/*
* This returns the average of three integers
* This is kept as an integer because the 
* question implies that there is no decimal
* points in the answers.
*/
int average_func(int a, int b, int c)
{
    return (a+b+c)/3;
}

