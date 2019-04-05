/*
 NAME: Daniel Gallagher
 STUDENT ID: 18401492
 * 
 Set 3
 Question 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void enter();
void leave();
void payment_made();
void at_concert();

//Global Variables
int total_audience = 0;

int ticket_cost = 20;

bool exit_program = false;

int main(int argc, char** argv) {
    
    char input;
    
    /*
     Four Functions: Enter, Leave, 
     Print Number of People & Register Payments
     
     COMMANDS:
     * E -> Enter
     * L -> Leave
     * X -> Print Amount At Concert
     * 0 -> Terminate The Program
 
     */
    
    printf("Input Commands And Press Enter\n");
    
    while (!exit_program)
    {
        scanf("%c", &input);
        
        switch(input)
        {
            case 'E':
                enter();
                payment_made();
                break;
                
            case 'L':
                leave();
                break;
                
            case 'X':
                at_concert();
                break;
                
            case '0':
                exit_program = true;
              
        }
        
        printf("\n");
    }
    
}

void enter()
{
    total_audience++;
}

void leave()
{
    total_audience--;
}

void payment_made()
{
    //Static Variable
    static int money_received = 0;
    
    money_received += ticket_cost;
    
    printf("Total Money Received: %d\n", money_received);
}

void at_concert()
{
    printf("Total people in audience: %d\n", total_audience);
}
