#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>


// On initialise la table de Bingo du joueur
int *BingoTable;
BingoTable=malloc(sizeof(int)*4*5);


// On initialise un vecteur qui va vérifier qu'on ne répète pas le même nombre 2 fois
int *CheckNumber;
CheckNumber=malloc(sizeof(int)*100);


//Random integer generaotr between 1 and 100
int randomintgenerator(){

}


//

int main ()


{
  for (unsigned int i=0; i<4;i++)
  {
    int a,b,c,d,e;

    printf(" Please input your first line numbers ! \n", );
    printf(" Only Integers between 1 and 100 !\n", );

    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);

      if(!a || !b || !c || !d || !e)
        printf("Failed to get numbers for line number %d", i);
        
    BingoTable[i]=(a,b,c,d,e);
  }


  }


//    SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_OPENGL, &window, &renderer);
}
