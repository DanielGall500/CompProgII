/*
 Name: Daniel Gallagher
 Student ID: 18401492
 
 Set 5 
 Question 3
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_SIZE 5

void max_min_parties(double *score_arr, int *min_party_indx,int *max_party_indx, int arr_size);
double average(double score, int user_count);

int main(int argc, char** argv) {
    
    //Initialise string array of parties and party scores array
    char *parties[LIST_SIZE] = {"FineF", "FineG", "SinnF", "GreenP", "IndependA"};
    double party_scores[LIST_SIZE] = {0,0,0,0,0}; //default is zero
    
    double score; //handles party score input
    char c; //used to check if there's another user
    int user_counter = 0;
    
    bool end_input = false;
    
    do
    {
        user_counter++;
        
        
        //Take scores for each party
        for(int i = 0; i < LIST_SIZE; i++)
        {
            printf("How would you rate %s out of 10?\n", parties[i]);
            scanf("%lf", &score);
            
            party_scores[i] += score;
        }
        
        
        c = ' ';
        while (c != 'Y' && c != 'N')
        {
            //Check if there's another user
            printf("Is there another user? (Y/N)\n");
            scanf(" %c", &c);

            //If there's not, end the loop
            if(c == 'N')
            {
                end_input = true;
            }
            else if (c != 'Y')
            {
                printf("Invalid Input \nTry Again \n");
            }
        }
        
    } while(!end_input);
    
    for(int i = 0; i < LIST_SIZE; i++)
    {
        //Average of each party
        double avg = average(party_scores[i], user_counter);
        
        //Print out each party's average rating
        printf("%s Summary\n", parties[i]);
        printf("Average Rating: %lf\n\n", avg);
    }
    
    int max_party_indx, min_party_indx;
    
    //Function finds parties with max and min scores
    max_min_parties(&party_scores[0], &min_party_indx, &max_party_indx, LIST_SIZE);
    
    
    //Highest Rated Party 
    printf("HIGHEST Rated Party: %s\n", parties[max_party_indx]);
    printf("Rating: %lf\n\n", average(party_scores[max_party_indx], user_counter));
    
    
    //Lowest Rated Party
    printf("LOWEST Rated Party: %s\n", parties[min_party_indx]);
    printf("Rating: %lf\n", average(party_scores[min_party_indx], user_counter));
    
}

void max_min_parties(double *score_arr, int *min_party_indx,int *max_party_indx, int arr_size)
{
    double min = *score_arr;
    double max = *score_arr;
    
    *max_party_indx = 0;
    *min_party_indx = 0;
    
    for(int i = 0; i < arr_size; i++)
    {
        //Set new max
        if(max < *score_arr)
        {
            max = *score_arr;
            *max_party_indx = i;
        }
        
        //Set new min
        if(min > *score_arr)
        {
            min = *score_arr;
            *min_party_indx = i;
        }
        
        //Move to next element in array
        *score_arr++;
    }
}

double average(double score, int user_count)
{
    return score / user_count;
}