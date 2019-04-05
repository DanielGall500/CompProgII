/*
 Daniel Gallagher
 18401492
 
 S6
 Q1
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_consonant(char c);
bool is_letter(char c);
bool is_uppercase(char c);

char *vowels = "aeiou";
char vowels_len = 5;

int main(int argc, char** argv) {

    //ARRAY VARIABLES
    char slogan[80] = "Comp10120 is my favourite module";
    char new_string[80];
    
    char *orig, *cpy;
    
    orig = slogan;
    cpy = new_string;
    
    int str_len = strlen(slogan);
    
    while(*orig)
    {
        bool letter = is_letter(*orig);
        bool upper = is_uppercase(*orig);
            
        if(!is_consonant(*orig))
        {
            if(upper || !letter) //uppercase letter OR digit
            {
                *cpy = *orig;
                *cpy++;
            }
            else if(!upper) //lowercase letter
            {
                *cpy = *orig - 32;
                *cpy++;
            }
        }
       
        *orig++;
    }
    
    //PRINT OUT COPED STRING
    for(int i = 0; i < str_len; i++)
    {
        printf("%c",new_string[i]);
    }
        
}
    
    
    


bool is_consonant(char c)
{
    char *vowels = "aeiou";
    int num_vowels = 5;
    
    if(!is_letter(c))
    {
        return false;
    }

    while(*vowels != '\0')
    {
        if(c == *vowels)
        {
            return false;
        }
        vowels++;
    }
    
    return true;
}

bool is_uppercase(char c)
{
    if(c > 64 && c < 91)
    {
        return true;
    }
    return false;
}

bool is_letter(char c)
{
    int c_int = (int)c;
    
    if((c_int >= 97 && c_int <= 122) || (c_int >= 65 && c_int <= 90))
    {
        return true;
    }
    return false;
}

