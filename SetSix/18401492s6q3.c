/*
 Daniel Gallagher
 18401492
 
 S6 
 Q2
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CHAR 50
#define NUM_GAMES 1000

typedef struct game_data 
{
    char title[MAX_CHAR], platform[MAX_CHAR], dev[MAX_CHAR];
    unsigned int year;
    
    bool is_borrowed;
    char borrower_name[MAX_CHAR];
    char borrow_date[7]; //e.g 01/02/19
} game_data;

void update_borrow_details(FILE *fPtr);
void append_new_game(FILE *fPtr);

int main(int argc, char** argv) {
    
    FILE *cfPtr;
    
    if((cfPtr = fopen("accounts.dat", "rb+")) == NULL)
    {
        printf("File Could Not Be Opened\n");
    }
    else
    {
        for(unsigned int i = 0; i < NUM_GAMES; i++)
        {
            printf("\n-Game %d-\n", i+1);
            append_new_game(cfPtr);
        }
        
        fclose(cfPtr);
    }
        
    
}
void append_new_game(FILE *fPtr)
{
    game_data g = {"", "", "", 0, false, "", ""};
    
    printf("Enter Title, Platform, Developer & Year\n");
    fscanf(stdin, "%14s%9s%s%u", g.title, g.platform, g.dev, &g.year); 
    
     
    char c;
    printf("Is this game being borrowed currently? (Y/N)\n");
    scanf(" %c", &c);
    
    if(c == 'Y' || c == 'y')
    {
        g.is_borrowed = true;
        
        printf("Enter the name of the borrower: \n");
        scanf("%s", g.borrower_name);
        
        printf("Enter the date borrowed (e.g DD/MM/YY)\n");
        scanf("%s", g.borrow_date);
    }
    
    fwrite(&g, sizeof(game_data), 1, fPtr);
    
}

