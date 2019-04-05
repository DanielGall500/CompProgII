/*
 Daniel Gallagher
 18401492
 
 Set 8
 Question 2
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Function to calculate the average
float average(float total, int num_elements);

/*
 IS_FLOAT will be used throughout to adjust our code based on
 the user choosing a float or integer array */

bool IS_FLOAT;

int main(int argc, const char * argv[]) {
    
    //Input Variables
    const int type_len = 10;
    char type_inp[type_len];
    
    unsigned int num_elements;
    
    //Input
    printf("Enter the type(integer or float)\n");
    fgets(type_inp, type_len, stdin); //newline
    
    //Check if type is integer or float
    if(strcmp(type_inp, "integer") == 0) IS_FLOAT = false;
    else IS_FLOAT = true;
    
    printf("Enter the number of elements you wish to store: ");
    scanf("%u", &num_elements);
    
    /*
     Allocate memory to an array based on the 
     user input.
     */
    int *i_arr;
    float *f_arr;
    
    //We allocate to a float array if the user chose a float array and
    //to the integer array if the user chose an integer array.
    
    if(IS_FLOAT)
    {
        f_arr = calloc(num_elements, sizeof(int));
    }
    else
    {
        i_arr = calloc(num_elements, sizeof(int));
    }
    
    
    //Enter the values
    int val_num;
    for(val_num = 0; val_num < num_elements; val_num++)
    {
        printf("Enter Value %d:\n", val_num+1);
        
        float f_inp;
        int i_inp;
        
        //Add input to array based on type
        if(IS_FLOAT)
        {
            scanf("%f", &f_inp);
            f_arr[val_num] = f_inp;
        }
        else
        {
            scanf("%d", &i_inp);
            i_arr[val_num] = i_inp;
        }
        
    }
    
    //Calculate the average
    float total = 0;
    for(int i = 0; i < num_elements; i++)
    {
        if(IS_FLOAT) total += f_arr[i];
        else total += i_arr[i];
    }
    
    printf("Average: %f\n", average(total, num_elements));
    
    char x;
    unsigned int y;
    
    printf("Is there more elements to be added? (Y/N)");
    scanf(" %c", &x);
    
    if(x == 'Y')
    {
        printf("How many?\n");
        scanf(" %u", &y);
        
        /*
         Reallocate memory to the array based on the additional elements
         that you wish to add to the array.
         
         If the original size of the array is 10, and you wish to add 3 elements,
         we extend the array so that it's memory size is changed from 10 to 13.
         */
        
        i_arr = realloc(i_arr, (y+num_elements)*sizeof(int));
        f_arr = realloc(f_arr, (y+num_elements)*sizeof(float));
        
        //Enter Additional Values
        for(int i = num_elements; i < (y + num_elements); i++)
        {
            int i_val;
            float f_val;
            
            printf("Enter Value %d\n", i+1);
            
            if(IS_FLOAT)
            {
                scanf("%f", &f_val);
                f_arr[i] = f_val;
            }
            else
            {
                scanf("%d", &i_val);
                i_arr[i] = i_val;
            }
        }
        
        //Calculate the updated average
        float total = 0;
        for(int i = 0; i < y+num_elements; i++)
        {
            if(IS_FLOAT) total += f_arr[i];
            else total += i_arr[i];
        }
        
        printf("Average(Updated Elements): %f\n", average(total, num_elements+y));
    }
    
    
}

float average(float total, int num_elements)
{
    //Average = Total Divided By The Number Of Elements
    return total / num_elements;
}
