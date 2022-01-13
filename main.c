#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

int a,b,c,d,e;
char ans;
int seed;
int rnum;

// On initialise la table de Bingo du joueur
int *BingoTable;


// On initialise un vecteur qui va vérifier qu'on ne répète pas le même nombre 2 fois
int *CheckNumber;


// Play function
void play (int* BingoTable)
{
  rnum=rand()%100;

}


//

int main ()

{
  BingoTable=(int*)malloc(sizeof(int)*4*5);
  CheckNumber=(int*)malloc(sizeof(int)*100);

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

    printf("Input 5 different number for line number : %d \n \n", i%5+1);
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    printf("\n");

      if(!a || !b || !c || !d || !e)
      {
        printf("Failed to get numbers for line number %d \n", i%5 +1);
        break;
      }

    BingoTable[i+0]=a;
    BingoTable[i+1]=b;
    BingoTable[i+2]=c;
    BingoTable[i+3]=d;
    BingoTable[i+4]=e;
  }

  printf("Voici notre matrice : \n");
  for(unsigned int i=0; i<4;i++)
  {
    for(unsigned int j=0;j<5;j++)
    {
      printf("%d ", BingoTable[5*i+j]);
    }
    printf("\n");
  }

  printf("%d\n",rand()%101);
  return 0;

  free(BingoTable);
  free(CheckNumber);


}


//    SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_OPENGL, &window, &renderer);
