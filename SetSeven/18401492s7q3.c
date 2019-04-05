#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jumble(char *arr[], int N);
void print_words(char *arr[], int N);
void random_word(char *arr[], int N, char *word);

int main(int argc, char** argv) {
    srand(time(NULL));
    
    char *words[] = {
        "COMP10120", 
        "is", "my", 
        "favourite", 
        "module", 
        "and", 
        "I", 
        "learn", 
        "lots", 
        "of", 
        "interesting", 
        "things"
    };
    
    //NON-JUMBLED WORDS
    printf("Print Words: No Jumble\n");
    print_words(words, 12);
    
    printf("\n\n");
  
    
    //JUMBLE THE WORDS
    printf("Print Words: Jumble\n");
    
    jumble(words, 12);
    
    print_words(words, 12);
    
    printf("\n\n");
    
    //SELECT RANDOM WORD
    printf("Select Random Word:\n");
    char word[10];
    random_word(words, 12, word);
    
    printf("%s", word);
}

void jumble(char *arr[], int N)
{
    for(int i = 0; i < N; i++)
    {
        //select a random index in the array
        int rand_indx = rand() % N;
        
        
        //swap the element i with this random element
        char *temp = arr[i];
        
        arr[i] = arr[rand_indx];
        arr[rand_indx] = temp;
        
    }
}

void print_words(char *arr[], int N)
{
    for(int i = 0; i < N; i++)
    {
        printf("%s ", arr[i]);
    }
}

void random_word(char *arr[], int N, char *word)
{
    int rand_indx = rand() % N;
    
    strcpy(word,arr[rand_indx]);
}

