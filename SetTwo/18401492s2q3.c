/*
 Name: Daniel Gallagher
 Student ID: 18401492
 
 Set: 2
 Question: 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    
    //Variable Initialisation
    int rand_num, upper_main, upper_tndrbll, tndrbll_num;
    
    upper_main = 39;
    upper_tndrbll = 14;
    
    //Random Number Generator Setup
    
    //THe time library is useful for this as
    //the time in seconds is an integer which is constantly changing
    time_t t_var;
    time(&t_var);
    
    srand((unsigned)t_var);
    
    //Five Main Numbers
    printf("Set Of Five Main Numbers:\n");
    
    for(int i = 0; i < 5; i++)
    {
        rand_num = 1 + (rand() % upper_main);
        printf("(%d) %d\n", i+1, rand_num);
    }
    
    //Thunderball number
    tndrbll_num = 1 + (rand() % upper_tndrbll);
    printf("\nThunderball Number: %d\n", tndrbll_num);
    
}
