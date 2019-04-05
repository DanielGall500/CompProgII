/*
 Name: Daniel Gallagher
 Student ID: 18401492
 
 Set: 2
 Question: 1
 */

#include <stdio.h>

#define PI 3.14159265359

double ellipsoid_vol(double a, double b, double c);

int main(int argc, const char * argv[]) {
    
    //VARIABLES
    double a, b, c, volume;
    
    //How many times do we want the program to execute?
    //This is assigned in prog_iter
    int prog_iter = 4;
    
    
    //MAIN LOOP
    for(int i = 0; i < prog_iter; i++)
    {
        printf("Enter a,b,c axes: \n");
        scanf("%lf",&a);
        
        scanf("%lf",&b);
        
        scanf("%lf",&c);
        
        volume = ellipsoid_vol(a,b,c);
        
        printf("Volume: %lf\n\n", volume);
    }
    
}

//Formula: 4/3 * pi * a * b * c
double ellipsoid_vol(double a, double b, double c)
{
    return (4.0/3) * PI * a * b * c;
}



