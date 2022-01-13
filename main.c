#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include <SDL2/SDL.h>


int a,b,c,d,e;
char ans;
int seed;
int rnum;

// On initialise la table de Bingo du joueur
int *BingoTable;

// 1st checker


// On initialise un vecteur qui va vérifier qu'on ne répète pas le même nombre 2 fois
int *CheckNumber;


//
void CheckMatrice (int *BingoTable, int *CheckNumber)
{
  for(int i=0;i<5;i++)
  {
    if(a == BingoTable[i] || b == BingoTable[i] || c == BingoTable [i] || d == BingoTable[i] || e == BingoTable[i])
    {
      printf("Nice try bro! \n");
      break;
    }
  }
}


// Play function
void play (int *BingoTable)
{
  rnum=rand()%100;

}


//

int main ()

{
  BingoTable=(int*)malloc(sizeof(int)*4*5);
  CheckNumber=(int*)calloc(5,sizeof(int));

  printf(" --- Please input line numbers ! --- \n" );
  printf(" --- Only Integers between 1 and 100 ! --- \n" );
  printf(" --- They need to be different! Dont try to scam me ! --- \n");
  printf(" --- 4 Lines needed with 5 values for this Bingo Game --- \n \n");

  printf("--- Do you wish to input a specific seed to play with others? [y/n] --- \n");
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

  printf("Let's make your Bingo sheet now !\n");

  for(unsigned int i=0; i<20;i+=5)
  {

    printf("Input 5 different numbers for line number : %d \n (NO 0 REMEMBER!) \n", i%5+1);
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    printf("\n");

      if(!a || !b || !c || !d || !e)
      {
        printf("Failed to get numbers for line number %d \n", i%5 +1);
        break;
      }
      for(int j=0;j<5;j++)
      {
        if(a==CheckNumber[j] || b == CheckNumber[j] || c == CheckNumber[j] || d == CheckNumber [j] || e == CheckNumber[j])
        {
          printf("You didn't even put some effort in your cheating... \n");
          break;
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

  CheckMatrice(BingoTable,CheckNumber);

  printf("Voici notre matrice : \n");

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

  printf("%d\n",rand()%99 +1);
  return 0;

  free(BingoTable);
  free(CheckNumber);


}


//    SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_OPENGL, &window, &renderer);
