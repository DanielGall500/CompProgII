/*
 Name: Daniel Gallagher
 Student ID: 18401492
 
 Set: 2
 Question: 2
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int day_of_the_week(int date, int month, int year);

int main(int argc, const char * argv[]) {
    
    //Variables
    int d, m, y;
    int day_int;
    
    
    //Input Date, Month, Year
    printf("Insert a date (e.g input 4 for the 4th):\n");
    scanf("%d", &d);
    
    printf("Insert a month: (1=Jan, 2=Feb, etc)\n");
    scanf("%d", &m);
    
    printf("Insert a year:\n");
    scanf("%d", &y);
    
    //Execute Functions
    day_int = day_of_the_week(d,m,y);
    
    //Print Day
    
    printf("\n%d / %d / %d is a ",d,m,y);
    
    switch(day_int)
    {
        case 0:
            printf("Saturday");
            break;
            
        case 1:
            printf("Sunday");
            break;
            
        case 2:
            printf("Monday");
            break;
            
        case 3:
            printf("Tuesday");
            break;
            
        case 4:
            printf("Wednesday");
            break;
            
        case 5:
            printf("Thursday");
            break;
            
        case 6:
            printf("Friday");
            break;
            
        default:
            printf("\nINVALID DATE INPUTTED\n");
    }
    
}

int day_of_the_week(int date, int month, int year)
{
    
    /*
     With this formula, January and February
     are thought of as the 13th and 14th months
     of the previous year, respectively. 
     
     Therefore,
     if the user inputs the date 13/2/2000, we convert
     it into 13/14/1999 by decrementing the year and 
     setting the month equal to 14
     */
    if (month == 1)
    {
        month = 13;
        year--;
    }
    else if (month == 2)
    {
        month = 14;
        year--;
    }
    
    /*
     K = year of the century (i.e 19 for 2019)
     J = zero-based century (i.e 20 for 2019)
     
     */
    int K, J, h;
    int calc_1, calc_2, calc_3;

    
    K = year % 100;
    J = year / 100;
    
    
    //We will break the formula into three smaller calculations:
    
    calc_1 = ((13 * (month+1)) / 5);
    calc_2 = K + (K/4);
    calc_3 = (J/4) - 2*J;
    
    h = (date + calc_1 + calc_2 + calc_3);
    
    return (int)h % 7;
}







