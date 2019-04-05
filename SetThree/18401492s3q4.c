/*
 NAME: Daniel Gallagher
 STUDENT ID: 18401492
 * 
 Set 3
 Question 4
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 10

int find_max(int arr[], int size);
double find_avg(int arr[], int size);
bool eligible_for_discount(int max, double avg);

int main(int argc, char** argv) {

    int driver_data[ROWS][COLS] = {{3,1,3,4,6,7,3,2,5,3}, {2,2,2,3,4,4,3,3,3,2}, {5,6,7,6,5,3,3,3,3,3}, {3,3,3,3,4,4,3,2,1,3}, {2,3,4,6,6,2,5,1,3,3}};

    int input, input_indx;
    
    //INPUT
    printf("Enter Driver Number: ");
    scanf("%d", &input);
    
    //index of the driver in the array
    input_indx = input - 1;
    
    printf("Driver %d Summary\n\n", input);
    
    
    //Print Acceleration Recordings for selected driver
    
    printf("Acceleration Recordings: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", driver_data[input_indx][i]);
    }
    printf("\n");
    
    
    //Which trip had the max acceleration?
    
    int max_trip = find_max_trip(driver_data[input_indx], 10);
    
    printf("\nMax average acceleration for Driver 1 was in trip %d\n\n", max_trip);
    
    
    //What was the average acceleration for this drivers trips?
    double avg = find_avg(driver_data[input_indx], 10);
    
    printf("Average acceleration over all of Driver 1 trips: %lf\n\n", avg);
    
    //Does this driver qualify for a discount?
    bool discount = eligible_for_discount(driver_data[input_indx][max_trip-1], avg);
    
    switch(discount)
    {
        case true:
            printf("Discount: Discount Applied\n\n");
            break;
            
        case false:
            printf("Discount: No Discount to be applied\n\n");
            break;
    }
    
    //What is the average of all drivers?
    double total_sum, total_average;
    total_sum = 0;
   
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            total_sum += driver_data[i][j];
        }
    }
    
    total_average = total_sum / (ROWS*COLS);
    
    printf("The average acceleration of all drivers over all trips is: %lf", total_average);
    
}

int find_max_trip(int arr[], int size)
{
    int max = arr[0];
    int max_trip = 1;
    
    //We update the max variable as we iterate throught
    //the array
    for(int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_trip = i+1;
        }
    }
    
    return max_trip;
}

double find_avg(int arr[], int size)
{
    double sum = 0;
    
    //(sum)/(size)
    
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    
    return (sum / (double)size);
}

bool eligible_for_discount(int max, double avg)
{
    if (avg > 5 || max >= 6)
    {
        return true;
    }
    return false;
}

