/*
 
 Daniel Gallagher
 18401492
 
 Set 7
 Question 4
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

enum v_type {STRING, CHAR, INT, DOUBLE};

int adder(int i, ...);
int multiplier(int i, ...);
int myPrinter(int i, enum v_type t, ...);

int main(int argc, char** argv) {

    int add = adder(2, 3, 5); //add three and five
    int mult = multiplier(2, 3, 5); //multiply three and five
    
    //Can choose from STRING, CHAR, INT or DOUBLE
    myPrinter(2, INT, add, mult);
    
}

//ADDER FUNCTION
int adder(int i, ...)
{
    
    int total = 0;
    
    va_list ap;
    va_start(ap, i);
    
    for(int j = 0; j < i; j++)
    {
        //add to the total
        total += va_arg(ap,int);
    }
    
    va_end(ap);
    
    return total;
}

//MULTIPLIER FUNCTION
int multiplier(int i, ...)
{
    
    int total = 1;
    
    va_list ap;
    va_start(ap, i);
    
    for(int j = 0; j < i; j++)
    {
        //multiply the total
        total *= va_arg(ap,int);
    }
    
    va_end(ap);
    
    return total;
}

//PRINTER FUNCTION
int myPrinter(int i, enum v_type t, ...)
{
    va_list ap;
    va_start(ap, i);
    
    for(int j = 0; j < i; j++)
    {
        switch(t)
        {
            //change based on data type
            case STRING:
                printf("%s\n", va_arg(ap, char*));
                break;
                
            case CHAR:
                printf("%c\n", va_arg(ap, char));
                break;
                
            case INT:
                printf("%d\n", va_arg(ap, int));
                break;
                
            case DOUBLE:
                printf("%lf\n", va_arg(ap, double));
                break;
        }
    }
    
    va_end(ap);
    
}

