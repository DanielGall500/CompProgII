/*
 Name: Daniel Gallagher
 Student ID: 18401492
 
 Set: 2
 Question: 5
 
EXPLANATION OF THE PROGRAM:
 
Our function works through calculating the remainder of our input
number when we subtract powers of two from it. 
 
We start from the bit which has the highest value. Then we use the
remainder we calculated to find whether the next bit is a one or zero
like so:
 
    Remainder > 0   -> Append a 1
    Remainder < 0   -> Append a 0
    Remainder == 0  -> Append a 1, make all remaining bits (if any) a 0
 
Then we use RECURSIVE FUNCTIONS by calling our binary function again
except with our decimal number set as the remainder we found. The power
index is also decremented.
 
--EXAMPLES--
 
 First Example Number: 15
 
 -> find out how many bits it needs (in this case 4 bits)
 
 2^3   2^2    2^1    2^0
 
 8      4      2      0
 
 -> start at the largest power, in this case 2^3
 -> when the remainder is equal to zero we append a one and then make all the remaining bits zero
 
 (15 - 2^3) = 7, greater than 0,  thus append 1 and we keep going
 7 - 2^2 = 3, greater than 0, thus append 1 and we keep going
 3 - 2^1 = 1, greater than 0, thus append 1 and we keep going
 1 - 2^0 = 0, is equal to 0, thus append 1 and we stop (because it is now equal to zero)
 
 Binary Number: 1111
 
 
 
 Second Example Number: 16
 -> need an additional bit (2^4)
 
 16 - 2^4 = 0, thus we append a 1 and make all the remaining bits zero
 binary: 10000
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define BINARY_MAX_LENGTH 50

/*
 We will make these variables public to
 to allow our functions access to them 
 without passing pointers to the functions.
 
 This simplifies the design of the functions.
 */

char binary_number[BINARY_MAX_LENGTH];
int bin_indx = 0; //a public index for the array

//Function Declaration

void binary(int x, int power);
void append_binary_num(int zero_or_one);


int main(int argc, const char * argv[]) {
    
    
    //User Input
    int decimal;
    
    printf("DECIMAL TO BINARY CONVERTER\n");
    printf("Input a number: \n");
    scanf("%d", &decimal);
    
    
    //Execute Function
    binary(decimal, -1);
    
    
    //Print Result
    printf("Binary: %s\n", binary_number);
}

void binary(int x, int pow_indx)
{
    
    /*
     pow_indx is set to -1 if we are at the beginning of
     the function call and so no recursion has taken place
     yet. This is so we can figure out how many bits
     our decimal number will need.
     */
    
    if (pow_indx == -1)
    {
        /*
         This for loop finds how many bits we need for our
         number. We have to have an amount of bits which can
         sum to a number which is larger than or equal to the
         decimal number we inputted. 
         
         Our power index starts at 0. If x is greater than 2 to the
         power of zero, then we increment the power index and see if
         it's greater than x again. 
         
         We do this until our subtraction is negative or 
         equal to zero, meaning the power is greater than
         or equal to x.
         
         Our pow_indx is always one number too large so
         we will decrement it afterwards.
         */
         
        for (pow_indx = 0; (x - pow(2,pow_indx)) >= 0; pow_indx++);
        
        return binary(x, --pow_indx);
    }
    
    //This section is explained in detail at the beginning
    //of the program
    
    int remainder = x - ((int) pow(2, pow_indx));
    
    if (remainder > 0)
    {
        append_binary_num(1);
        
        return binary(remainder, --pow_indx);
    }
    else if(remainder < 0)
    {
        append_binary_num(0);
        
        return binary(x, --pow_indx);
    }
    else //remainer equals zero
    {
        append_binary_num(1);
        
        //male all remaining bits a zero
        for (int i = 0; i < pow_indx; i++)
        {
            append_binary_num(0);
        }
    }
}

/*This function append a binary number of 
 our choice to our public binary array.
 */
void append_binary_num(int zero_or_one)
{
    if (zero_or_one == 0)
    {
        strcpy(&binary_number[bin_indx++], "0");
    }
    else
    {
        strcpy(&binary_number[bin_indx++], "1");
    }
}







