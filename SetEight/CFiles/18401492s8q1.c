/*
 Daniel Gallagher
 18401492
 
 Set 8
 Question 1
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structs given to us in the question:
struct county{
    char *longName;
    char *shortName;
    unsigned int population;
};

struct town{
    char *name;
    unsigned int population;
    struct county aCounty;
};

#define LINE_LEN 50
#define DATA_LEN 15
#define NUM_ENTRIES 4

/*This enum is used to specify which piece of information we want to take
  from the file*/

enum DATA { C_NAME, C_SHORT, C_POPULATION, T_NAME, T_POPULATION, T_COUNTY };

//Search a string for a piece of information, based on the format of our text files
void search_str(char str[LINE_LEN], enum DATA v, char output[DATA_LEN]);

int main(int argc, const char * argv[]) {
    
    //**CHANGE BASED ON WHERE YOUR TEXT FILES ARE LOCATED**
    char *town_url = "/Users/dannyg/Desktop/CompSci/CompSci_Semester2/InProgress/CompProgII/S8/towns.txt";
    char *county_url = "/Users/dannyg/Desktop/CompSci/CompSci_Semester2/InProgress/CompProgII/S8/counties.txt";
    //*****************************************************
    
    //Initialise pointer to where the file is located and open the file
    FILE *townPtr = fopen(town_url, "r");
    FILE *countyPtr = fopen(county_url, "r");
    
    //Create two arrays of structs for the counties and towns, respectively
    struct county counties[NUM_ENTRIES];
    struct town towns[NUM_ENTRIES];
    
    int indx = 0;
    
    //Check if the file isn't found and exit if not
    if(townPtr == NULL || countyPtr == NULL)
    {
        printf("File(s) not found");
        exit(0);
    }
    
    //Initialise variables to hold our infromation form the text file
    char line[LINE_LEN];
    char c_name[DATA_LEN], c_short[DATA_LEN], c_population[DATA_LEN];
    
    
    //COUNTIES TEXT FILE
    while(fgets(line, LINE_LEN, countyPtr) != NULL)
    {
        //Search each line for the name, shortName and population
        search_str(line, C_NAME, c_name);
        search_str(line, C_SHORT, c_short);
        search_str(line, C_POPULATION, c_population);
        
        //Set longName e.g Wexford
        counties[indx].longName = malloc(sizeof(struct county) + sizeof(c_name));
        strcpy(counties[indx].longName, c_name);
        
        //Set shortName e.g WX
        counties[indx].shortName = malloc(sizeof(struct county) + sizeof(c_short));
        strcpy(counties[indx].shortName, c_short);
        
        //Set the population of each county into our struct array
        //We use the atoi function to convert our string to an int
        counties[indx].population = atoi(c_population);
        
        //Create placeholder county with our variables
        struct county y = { c_name, c_short, atoi(c_population) };
        
        //Add variables to country array
        counties[indx] = y;
        
        //Using our structs, print out the information within them
        printf("County %d\n", indx+1);
        printf("%s %s %d\n\n", counties[indx].longName, counties[indx].shortName, counties[indx].population);
        
        indx++;
    }
    
    char t_name[DATA_LEN], t_population[DATA_LEN], t_county[DATA_LEN];
    
    indx = 0;
    while(fgets(line, LINE_LEN, townPtr) != NULL)
    {
        search_str(line, T_NAME, t_name);
        search_str(line, T_POPULATION, t_population);
        search_str(line, T_COUNTY, t_county);
        
        /*Find which struct corresponds to the county of this town
          For example, if our town text file says "Wexford", we
          want to find the struct with longName "Wexford"*/
        int i;
        for(i = 0; i < NUM_ENTRIES; i++)
        {
            if(strcmp(t_county, counties[i].longName) == 0)
            {
                break;
            }
        }
        
        //Create placeholder town
        struct town x = { t_name, atoi(t_population), counties[i] };
        
        //Add it to our struct array
        towns[indx] = x;
        
        //Using structs, we print out the information about the towns
        printf("Town %d\n", indx+1);
        printf("%s %u\n\n", towns[indx].name, towns[indx].population);
        
        indx++;
    }
    
}

/*This function searches our string in order to find the information we need.
  
  This search is BASED ON THE SPACES IN BETWEEN OUR DATA POINTS
  One space detected means we're starting the second word, two spaces
  is the third word, etc. */

void search_str(char str[LINE_LEN], enum DATA v, char output[DATA_LEN])
{
    int i = 0;
    int spaces = 0;
    
    char new_str[DATA_LEN];
    char short_str[2];
    
    //Find the shortName for county or population for town
    if(v == C_SHORT || v == T_POPULATION)
    {
        //Find 1 space to get the second word
        while(spaces != 1)
        {
            if(str[i++] == ' ') spaces++;
        }
    }//Find the population for county or county for the town
    else if (v == C_POPULATION || v == T_COUNTY)
    {
        //Find 2 spaces to get the first word
        while(spaces != 2)
        {
            if(str[i++] == ' ') spaces++;
        }
    }
    
    //Add the data to a string
    int indx = 0;
    while(str[i] != ' ' && str[i] != '\0')
    {
        if(v == C_SHORT) short_str[indx++] = str[i++];
        else new_str[indx++] = str[i++];
    }
    
    //Set our output string in the parameters to our string containing the information
    if(v == C_SHORT) strcpy(output, short_str);
    else strcpy(output, new_str);
    
    //Empty our string
    new_str[0] = 0;
    
}










