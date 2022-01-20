#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "Tools.h"




void CheckMatrice (int *BingoTable, int *CheckNumber)
{
  for(int i=0;i<5;i++)
  {
    if(CheckNumber[0] == BingoTable[i] || CheckNumber[1] == BingoTable[i] || CheckNumber[2] == BingoTable [i] || CheckNumber[3] == BingoTable[i] || CheckNumber[4] == BingoTable[i])
    {
      printf("Nice try bro! \n");
      exit(EXIT_FAILURE);
    }
    if(BingoTable[0] == BingoTable[10+i] || BingoTable[1] == BingoTable[10+i] || BingoTable[2] == BingoTable [10+i] || BingoTable[3] == BingoTable[10+i] || BingoTable[4] == BingoTable[10+i])
    {
      printf("Nice try bro! \n");
      exit(EXIT_FAILURE);
    }
    else {continue;}
  }
}

void Header()
{
  printf(" --- Please input line numbers ! --- \n" );
  printf(" --- Only Integers between 1 and 100 ! --- \n" );
  printf(" --- They need to be different! Dont try to scam me ! --- \n");
  printf(" --- 4 Lines needed with 5 values for this Bingo Game --- \n \n");

  printf("--- Do you wish to input a specific seed to play with others? [y/n] --- \n");
}

void PrintMatrice(int *BingoTable)
{
  printf("-----------------------------------------------------\n");
  printf("-----------------------------------------------------\n");
  printf("\n");
  printf("Here's your Bingo Sheet : \n");
  #pragma omp parallel
  {
    for(unsigned int i=0; i<4;i++)
    {
      for(unsigned int j=0;j<5;j++)
      {
        printf("%d ", BingoTable[5*i+j]);
      }
      printf("\n");
    }
  }
  printf("\n");
  printf("-----------------------------------------------------\n");
  printf("-----------------------------------------------------\n");
}


void play (int *BingoTable, int *Rnumrolled, int *counter)
{
  int rnum;
  int points=0;
  int check;

  printf("Time to play ! \n");
  printf("You will need to press ENTER to generate a new random number ! \n");
  int j=0;
  for(;;)
  {
    getchar();
    rnum=rand()%100+1;
    for(int k=0; k<(*counter);k++)
    {
      if(rnum==Rnumrolled[k])
      {
        rnum=rand()%100+1;
        continue;
      }
      else
      {
        Rnumrolled[k]=rnum;
        counter+=1;
        break;
      }
    }
    printf("You rolled a %d !\n",rnum);
    printf("Let's see...\n");
    PrintMatrice(BingoTable);
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<5;j++)
      {
        if(rnum==BingoTable[5*i+j])
        {
          check=1;
          printf("Nice ! You gained a point !\n");
          break;
        }
        else
        {
          continue;
        }
      }
    }
    if(check==1)
    {
      points+=1;
      printf("Here's your total number of points : %d\n",points );
      check = 0;
    }
    else
    {
      printf("Sucks to suck, better luck next time :D !\n");
    }

  }
}

void seeding()
{
  char ans;
  int seed;
  scanf("%c",&ans);

  if(ans=='y')
  {
    printf("Please input your seed : \n");
    scanf("%d",&seed);
    srand(seed);
  }
  else
  {
    srand(time(NULL));
  }
}

void BingoSheet(int *BingoTable,int *CheckNumber)
{
  for(unsigned int i=0; i<20;i+=5)
  {
    int a,b,c,d,e;

    printf("Let's make your Bingo sheet now !\n");
    printf("Input 5 different numbers each time for each line ! Line number : %d \n (NO 0 REMEMBER!) \n", i%5+1);
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    printf("\n");

      if(a>100 || a==0 ||b>100 || b==0 ||c>100 || c==0 ||d>100 || d==0 ||e>100 || e==0)
      {
        printf("Follow/Read the rules next time :D ! \n");
        exit(EXIT_FAILURE);
      }

      for(int j=0;j<5;j++)
      {
        if(a==CheckNumber[j] || b == CheckNumber[j] || c == CheckNumber[j] || d == CheckNumber [j] || e == CheckNumber[j])
        {
          printf("You didn't even put some effort in your cheating... \n");
          exit(EXIT_FAILURE);
        }
      }

    BingoTable[i+0]=a;
    BingoTable[i+1]=b;
    BingoTable[i+2]=c;
    BingoTable[i+3]=d;
    BingoTable[i+4]=e;
    CheckNumber[0]=a;
    CheckNumber[1]=b;
    CheckNumber[2]=c;
    CheckNumber[3]=d;
    CheckNumber[4]=e;

  }
}
