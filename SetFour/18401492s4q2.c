/*
 Name: Daniel Gallagher
 Student ID: 18401492
  
 Set 4
 Question 2
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes - pay attention to the use of pointers instead of globla variables
void moveFirefoot( int *FirefootPtr);
void moveShadowfox( int *ShadowfoxPtr);
void printCurrentPositions(unsigned int, unsigned int);

int main()
{ 
   srand(time(NULL));

   int Firefoot  = 1; // Firefoot  current position
   int Shadowfox = 1; // Shadowfox current position      
   int counter = 0; // counter for the for loop controling the race.

 
   puts("The Race has started");
   
   // loop through the progress on the track
   while (Firefoot  != 100 && Shadowfox != 100) 
   { 
   //neither of the horses has reached the end of the track
   //call functions to move horses on the track


       moveFirefoot(&Firefoot);
       moveShadowfox(&Shadowfox);
       
       printCurrentPositions(Firefoot, Shadowfox);
       
       //this counts the amount of iterations it takes
       //to finish the race
       counter++;
      
   } 

   // determine the winner and print message - one horse has passed the end as it is outside the loop.
   if (Firefoot  > Shadowfox)
   {
       printf("FIREFOOT WINS\n");
   }          
   else if (Firefoot  < Shadowfox)
   {
      printf("SHADOWFOX WINS\n");
   }
   else
   {
       printf("TIED; BOTH WIN\n");
   } 

   printf("iterations: %d \n", counter);
} 

// progress for Shadowfox
void moveShadowfox( int *ShadowfoxPtr)
{ 
   // generate random number from 1-10
   int x = (rand() % 10) + 1;

   // determine progress
   if (x >= 1 && x <= 5) 
   {
   // full speed 50% of the time
       *ShadowfoxPtr += 2; //CHANGED TO 2 FROM SKELETON CODE
   } 
   //enter code here to test all the other rules
   else if(x == 6)
   {
       //1 space, 10% of the time
       *ShadowfoxPtr += 1;
   }
   else if(x == 7)
   {
       //3 spaces, 10% of the time
       *ShadowfoxPtr += 3;
   }
   else if(x == 8 || x == 9)
   {
       //minus 2 spaces, 20% of the time
       *ShadowfoxPtr -= 2;
   }
   //if it equals 10, do nothing
   
    
   // check boundaries
   
   if (*ShadowfoxPtr < 1) {
      *ShadowfoxPtr = 1;
   } 
   if (*ShadowfoxPtr > 100) {
      *ShadowfoxPtr = 100;
   } 
} 

// progress for Firefoot 
void moveFirefoot (int *FirefootPtr)
{ 
   // generate random number from 1-10
   int y = (rand() % 10) + 1;

   // determine progress
   if (y >= 1 && y <= 5) 
   {
   // full speed 50% of the time
       *FirefootPtr += 2; //CHANGED TO 2 FROM SKELETON CODE
   } 
   //enter code here to test all the other rules
   else if(y == 6)
   {
       //1 space, 10% of the time
       *FirefootPtr += 1;
   }
   else if(y == 7)
   {
       //3 spaces, 10% of the time
       *FirefootPtr += 3;
   }
   else if(y == 8 || y == 9)
   {
       //minus two spaces, 20% of the time
       *FirefootPtr -= 2;
   }
   //if it equals 10, do nothing
    
   
   // check boundaries
   if (*FirefootPtr < 1) {
      *FirefootPtr = 1;
   } 
   if (*FirefootPtr > 100) {
      *FirefootPtr = 100;
   } 
} 

// display new position
void printCurrentPositions(unsigned int Firefoot, unsigned int Shadowfox)
{ 
   // loop through race
   for (unsigned int count = 1; count <= 100; ++count) 
   {
      // this loop will print will 100 characters at each run: either P,N,T or a space to 
      //give the user an idea of where the horse at every iteration
      
      if (count == Firefoot  && count == Shadowfox) 
      {
          printf("T"); //Tied
      } 
      else if (count == Shadowfox) {

          printf("P"); //Shadowfox location
      } 
      else if (count == Firefoot ) {
          printf("N"); //Firefoot location
      } 
      else {
          printf(" ");
      } 
   }

   puts("");
} 
