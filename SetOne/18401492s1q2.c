/*
 18401492s1q2.c
 Set One
 Question Two
 
 Student ID: Daniel Gallagher
 Student Number: 18401492
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    /*
     Our first variable will set how many characters/digits
     are in our student ID
     
     Our second variable will be an array of characters.
     This will hold our student number separated into its
     characters.
     
     We can convert these characters to integers later in the
     program in order to sum them together.
     */
    int id_characters = 8;
    char student_id[id_characters];
   
    //This variable holds the sum of each number in the ID
    int id_sum = 0;
    
    //ENTER STUDENT ID
    printf("Enter your student ID:\n");
    fgets(student_id, id_characters+1, stdin);
    
    //ITERATES THROUGH STUDENT ID
    for (int i = 0; i < id_characters; i++)
    {
        char num = student_id[i];
        
        //Print out the digit/character
        printf("%c\n",num);
        
        /*
         We can convert the character to an integer
         by subtracting the '0' character.
         
         We then add this to the ID sum
         */
        
        id_sum += (num - '0');
    }
    
    
    //Print out the final sum
    printf("Sum is %d", id_sum);
    
    
}

