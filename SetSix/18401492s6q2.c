/*
 Daniel Gallagher
 18401492
 
 S6
 Q2
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHARACTERS 50

void print_student_summary(char *filename);

char input_fields[6][MAX_CHARACTERS] = {"FirstName","Surname","StudentID","Phone","Field","GPA"};
int num_students = 0;
char filename[20] = "students.txt";

int main(int argc, char** argv) {
    
    FILE *file;
    file = fopen(filename, "w");
    
    char end_inp[3] = "EOF";
    bool input_finished = false;
    
    if(file == NULL)
    {
        printf("FILE COULD NOT BE OPENED\n");
    }
    else
    {
        
        while(!feof(stdin))
        {
            /*Set: {FIRSTNAME,SURNAME,STUDENT NUMBER,PHONE NUMBER,FIELD,GPA}
         
            We read numbers as strings because for example if we input
            the phone number 085... then it will not register the 0
            at the beginning unless we use a string */
            
            char new_student[6][MAX_CHARACTERS];
            
            printf("-Student %d-\n",num_students+1);
            printf("Enter student's first name, surname, student number, phone number, field of study, and GPA\n");
            printf("Enter EOF to end input.\n");

            for(int i = 0; i < 6; i++)
            {
                //Input
                char input[MAX_CHARACTERS];
                fgets(input,MAX_CHARACTERS,stdin);
                
                //Remove Newline
                int str_len = strlen(input);
                
                if(input[str_len-1] == '\n')
                {
                    input[str_len-1] = '\0';
                }
                
                //Check for end input request
                if(strcmp(input,"EOF") == 0)
                {
                    input_finished = true;
                    break;
                }
                
                //INVALID DATA CHECK
                if(i == 2 && strlen(input) != 8) 
                {
                    printf("INVALID STUDENT ID, TRY AGAIN\n");
                    i--;
                }
                else if(i == 3 && strlen(input) != 10)
                {
                    printf("INVALID PHONE NUMBER, TRY AGAIN\n");
                    i--; 
               }
                else
                {
                    fprintf(file, "%s,", input);
                }
            }
            
            if(input_finished)
            {
                break;
            }

            fprintf(file, "\n");

            printf("\n\n");

            num_students++;
            
        }
        
        fclose(file);
        
        print_student_summary(filename);
    } 
    
    
    
}

void print_student_summary(char *filename)
{
    FILE *filePtr = fopen(filename, "r");
    char line[100];
    
    char studentIDs[2][8]; 
    int current_student, current_item;
    
    current_student = 1, current_item = 1; //first item, first student
    
    if(filePtr == NULL)
    {
        printf("FILE COULD NOT BE OPENED\n");
        exit(0);
    }
    
    //read student ID and gpa, 3rd and 6th respectively  
    while(fgets(line, 100, filePtr) != NULL)
    {
        int student_id_item = 3;
        int gpa_item = 6;
        
        int pos = 0;
        current_item = 1;
        
        char student_id[8];
        char gpa[4]; //decimal point included
        
        //STUDENT ID
        while (current_item != student_id_item)
        {
            char c = line[pos];
            
            if(c == ',') current_item++;
            
            pos++;
        }
        
        for(int id_size = 0; id_size < 8; id_size++)
        {
            student_id[id_size] = line[pos];
            pos++;
        }
        
        //GPA
        while (current_item != gpa_item)
        {
            char c = line[pos];
            //printf("%c",c);
            
            if(c == ',') current_item++;
            
            pos++;
        }
        
        int gpa_pos = 0;
        while(line[pos] != '\n' && gpa_pos < 3)
        {
            gpa[gpa_pos] = line[pos];
            
            pos++;
            gpa_pos++;
            
        }
        
        //FIGURE OUT GRADE
        double gpa_dbl = strtod(gpa, NULL);
        char gpa_award[50];
        
        if(gpa_dbl >= 3.68)
        {
            strcpy(gpa_award,"1st Class Honors");
        }
        else if(gpa_dbl >= 3.08)
        {
            strcpy(gpa_award,"2nd Class Honors, Grade 1");
        }
        else if(gpa_dbl >= 2.48)
        {
            strcpy(gpa_award,"2nd Class Honors, Grade 2");
        }
        else if(gpa_dbl >= 2)
        {
            strcpy(gpa_award,"Pass");
        }
        else
        {
            strcpy(gpa_award,"Fail");
        }
        
        //PRINT OUTPUT
        printf("Student ID: %s\n", student_id);
        printf("Award: %s\n\n", gpa_award);
        
    }
    
    fclose(filePtr);
}
