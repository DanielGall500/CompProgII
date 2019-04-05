/*
 18401492s1q3.c
 Set One
 Question Three
 
 Student ID: Daniel Gallagher
 Student Number: 18401492
 */

#include <stdio.h>
#include <stdlib.h>

int cost_calculation(int num_bags);

int main(int argc, char** argv) {
    
    int num_bags, cost;

    //USER INPUT: Number of bags
    printf("Enter the number of bags to be purchased:\n");
    scanf("%d",&num_bags);
    
    //FUNCTION TO CALCULATE COST (explained below)
    cost = cost_calculation(num_bags);
    
    //PRINT RESULTS
    printf("Total Cost: €%d", cost);
    
}

int cost_calculation(int num_bags)
{
    if (num_bags <= 10)
    {
        //€10 per bag
        return (10*num_bags);
    }
    else if(num_bags <= 50)
    {
        //€10 for the first 10 bags,
        //€9.50 for the rest (total number of bags minus ten)
        return (10*10 + 9.50*(num_bags-10));
    }
    else
    {
        //€10 for the first 10 bags,
        //€9.50 for the next 40 bags,
        //€9 for the rest (total number of bags minus fifty)
        return (10*10 + 9.50*40 + 9*(num_bags-50));
    }
}

