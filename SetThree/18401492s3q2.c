/*
 NAME: Daniel Gallagher
 STUDENT ID: 18401492
 * 
 Set 3
 Question 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool contains(int arr[], int num, int size);
void print_arr(int arr[], int size);

int main(int argc, char** argv) {
    
    unsigned int rows, cols;
    
    //INPUT
    do
    {
        printf("Rows: ");
        scanf("%d", &rows);
        printf("\n");

        printf("Columns: ");
        scanf("%d", &cols);
        printf("\n");

        //Check for arrays that are too large
        if (rows > 20 || cols > 20)
        {
            printf("Rows and Columns must be less than or equal to 20\n");
        }
     
    } while (rows > 20 || cols > 20);
    
    
    int arrayA[rows][cols], arrayB[rows][cols];
    
    /*
     arr_prod -> product of our arrays
     arr_sum -> sum of our arrays
     arr_sum_rows -> sum the rows of each array together
     arr_sum_cols -> sum the columns of each array together*/
    int arr_prod[rows][cols], arr_sum[rows][cols];
    int arr_sum_rows[rows], arr_sum_cols[cols];
    
    //we want numbers between 100 and 1500
    int lower_range, higher_range;
    lower_range = 100;
    higher_range = 1500;
    
    //time always changes, no duplicates
    srand(time(NULL)); 
    
    
    for (int r = 0; r < rows; r++)
    {
        int row_sum = 0;
        int col_sum = 0;
        
        for(int c = 0; c < cols; c++)
        {
            arrayA[r][c] = (rand() % (higher_range-lower_range)) + lower_range;
            arrayB[r][c] = (rand() % (higher_range-lower_range)) + lower_range;
            
            //If they're the same, print 'Wow'
            if(arrayA[r][c] == arrayB[r][c])
            {
                printf("\nWow\n");
            }
            
            arr_prod[r][c] = arrayA[r][c] * arrayB[r][c];
            arr_sum[r][c] = arrayA[r][c] + arrayB[r][c];
            
            row_sum += (arrayA[r][c] + arrayB[r][c]);
            col_sum += (arrayA[c][r] + arrayB[c][r]);
 
        }
        
        arr_sum_rows[r] = row_sum;
        arr_sum_cols[r] = col_sum;
     
    }
    
    //Print Array A
    printf("\nArray A:\n");
    for(int i = 0; i < rows; i++)
    {
        print_arr(arrayA[i], cols);
    }
    
    //Print Array B
    printf("\nArray B:\n");
    for(int i = 0; i < rows; i++)
    {
        print_arr(arrayB[i], cols);
    }
    
    
    //Find out how many numbers are contained in both arrays
    int mutual_nums = 0;
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(contains(arrayA[i], arrayB[i][j], cols))
            {
                mutual_nums++;
            }
        }
    }
    printf("\nTotal Mutual Numbers: %d\n", mutual_nums);
    
   
            
}

//Does the array contain an integer
bool contains(int arr[], int num, int size)
{
    for(int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

//Print out a one dimensional array
void print_arr(int arr[], int size)
{
    
    for(int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    printf("\n");
}



