/*
 18401492s1q5.c
 Set One
 Question Five
 
 Student ID: Daniel Gallagher
 Student Number: 18401492
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double ratio(int a, int b);
bool is_overcrowded(double ratio);

int main(int argc, char** argv) {
    
    int num_people, occupied_rooms;
    double crowd_ratio;
    
    /*
     We need two pieces of information:
     - Number of Rooms 
     - Number of People
     
     The number of bathrooms DOES NOT COUNT towards the
     overcrowd ratio
     */
    
    printf("How many rooms are in the house(excluding bathrooms, including kitchens and living rooms)?\n");
    scanf("%d", &occupied_rooms);
    
    printf("How many people are living in the house?\n");
    scanf("%d", &num_people);
    
    
    /*
    This information allows us to calculate the overcrowd ratio. This is the
    ratio of people to occupied rooms.
    
     If the ratio is greater than 2, the child is living in an 
     overcrowded home.
     
     A function is created below which calculates the 
     ratio of two numbers by dividing them.
     
    */
    
    crowd_ratio = ratio(num_people, occupied_rooms);
    
    //Print the overcrowd ratio 
    printf("Overcrowd Ratio: %lf\n", crowd_ratio);
    
    /*
     A boolean function has been created called is_overcrowded
     which returns true if the overcrowd ratio is greater than 
     two and false if it is less than or equal to two.
     */
    
    if (is_overcrowded(crowd_ratio))
    {
        printf("The Child Is Living In An Overcrowded House");
    }
    else
    {
        printf("The Child's Not Living In An Overcrowded House");
    }
    
}

bool is_overcrowded(double ratio)
{
    //If the overcrowd ratio is greater than two,
    //the child is living in an overcrowded house
    
    if (ratio > 2)
    {
        return true;
    }
    return false;
}

double ratio(int a, int b)
{
    //we convert the integers to a double
    //using the (double) cast
    return (double)a / b;
}

