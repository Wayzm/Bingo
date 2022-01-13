#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

int a,b,c,d,e;

// On initialise la table de Bingo du joueur
int *BingoTable;


// On initialise un vecteur qui va vérifier qu'on ne répète pas le même nombre 2 fois
int *CheckNumber;


//Random integer generaotr between 1 and 100
int randomintgenerator(){
 return 1;
}


//

int main ()


{
  printf(" Please input line numbers ! \n" );
  printf(" Only Integers between 1 and 100 !\n" );
  printf(" They need to be different! Dont try to scam me")
  for (unsigned int i=0; i<4;i++)
  {
    BingoTable=(int*)malloc(sizeof(int)*4*5);
    CheckNumber=(int*)malloc(sizeof(int)*100);

    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);

      if(!a || !b || !c || !d || !e)
        printf("Failed to get numbers for line number %d", i);

    BingoTable[i]=(a,b,c,d,e);
  }

  return 0;

}


//    SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_OPENGL, &window, &renderer);
