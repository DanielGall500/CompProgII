/*
 18401492s1q4.c
 Set One
 Question Four
 
 Student ID: Daniel Gallagher
 Student Number: 18401492
 */

#include <stdio.h>
#include <stdlib.h>

char bp_analysis(int sys_bp, int dia_bp);

int main(int argc, char** argv) {
    
    int systolic_bp, diastolic_bp;
    char bp_result;
    
    /*
     * We will identify which type of blood pressure
     * we have using a function which analyses the 
     * numbers and returns a single character. This
     * function is explained further below.
     * 
     * Characters to Strings:
     * 'H' = High Blood Pressure
     * 'P' = Pre-High Blood Pressure
     * 'I' = Ideal Blood Pressure
     * 'L' = Low Blood Pressure
     * 
     */
    
    //USER INPUT
    printf("Enter Systolic Pressure: ");
    scanf("%d", &systolic_bp);
    
    printf("Enter Diastolic Pressure: ");
    scanf("%d", &diastolic_bp);
    
    //FUNCTION CALL
    bp_result = bp_analysis(systolic_bp, diastolic_bp);
    
    printf("Blood Pressure: ");
    
    
    /*
     * This next switch statement is used to print
     * out our blood pressure type based on the
     * character returned to the variable 'bp_result' 
     */
    
    switch(bp_result)
    {
        case 'H':
            printf("High");
            break;
            
        case 'P':
            printf("Pre-High");
            break;
            
        case 'I':
            printf("Ideal");
            break;
            
        case 'L':
            printf("Low");
            break;
    }
    
    
    
    
}

/*
 * This functions returns a character that
 * symbolizes our blood pressure type
 * 
 * The numbers below in the if else
 * statements are provided by the 
 * report given in the question
 */
char bp_analysis(int sys_bp, int dia_bp)
{
    /*
     * sys_bp -> systolic blood pressure
     * dia_bp -> diastolic blood pressure
     */
    
    if (sys_bp >= 140 || dia_bp >= 90)
    {
        return 'H';
    }
    else if (sys_bp >= 120 || dia_bp >= 80)
    {
        return 'P';
    }
    else if (sys_bp >= 90 || dia_bp >= 60)
    {
        return 'I';
    }
    
    return 'L';
}

