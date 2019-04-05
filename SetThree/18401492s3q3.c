/*
 NAME: Daniel Gallagher
 STUDENT ID: 18401492
 * 
 Set 3
 Question 3
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool can_be_multiplied(int row_one[], int dim_two[]);

int main(int argc, char** argv) {
    
    int m1_rows, m1_cols;
    int m2_rows, m2_cols;

    //INPUT ARRAY DIMENSIONS
    printf("Input the dimensions of two 2-Dimensional arrays\n");
    
    printf("Array One \nRows: ");
    scanf("%d", &m1_rows);
    printf("Columns: ");
    scanf("%d", &m1_cols);
    
    printf("Array Two \nRows: ");
    scanf("%d", &m2_rows);
    printf("Columns: ");
    scanf("%d", &m2_cols);
    
    int dim_one[2] = {m1_rows, m1_cols};
    int dim_two[2] = {m2_rows, m2_cols};
    
    //Check if this is a valid matrix multiplication
    //If not, terminate the program
    if(!can_be_multiplied(dim_one,dim_two))
    {
        printf("ERROR - PRODUCT CANNOT BE CALCULATED");
        exit(0);
    }
    
    int mat_one[m1_rows][m1_cols];
    int mat_two[m2_rows][m2_cols];
    
    //INPUT FIRST ARRAY
    printf("\nARRAY ONE - Size: (%d, %d)", m1_rows, m1_cols);
    int element;
    
    for(int i = 0; i < m1_rows; i++)
    {
        for(int j = 0; j < m1_cols; j++)
        {
            printf("\nEnter element in row %d and column %d: ", i+1, j+1);
            scanf("%d",&element);
            
            mat_one[i][j] = element;
        }
    }
    
    //INPUT SECOND ARRAY
    printf("\nARRAY TWO - Size: (%d, %d)", m2_rows, m2_cols);
    for(int i = 0; i < m2_rows; i++)
    {
        for(int j = 0; j < m2_cols; j++)
        {
            printf("\nEnter element in row %d and column %d: ", i+1, j+1);
            scanf("%d",&element);
            
            mat_two[i][j] = element;
        }
    }
    
    //Create new array for resulting multiplication
    int new_rows, new_cols;
    new_rows = dim_one[0], new_cols = dim_two[1];
    
    /*
     To simpify things we will set the dimensions
     of our original array equal to n, m and p:
    
     A Dimensions: n x m
     B Dimensions: m x p
     */
    
    int n,m,p;
    
    n = dim_one[0];
    m = dim_two[0];
    p = dim_one[1];
    
    int sum;
    
    int new_mat[new_rows][new_cols]; //our new matrix
    
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            sum = 0;
            
            for(int k = 0; k < m; k++)
            {
                sum += (mat_one[i][k] * mat_two[k][j]);
            }
            new_mat[i][j] = sum;
        }
    }
    
    
    //Print out resulting array
    printf("Multiplied: A x B\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < p; j++)
        {
            printf("%d, ", new_mat[i][j]);
        }
        printf("\n");
    }
    
    
}

//Checks if the two matrices can be multiplied 
bool can_be_multiplied(int dim_one[], int dim_two[])
{
    if(dim_one[1] == dim_two[0])
    {
        return true;
    }
    return false;
}


