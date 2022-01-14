#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "Tools.h"

int *BingoTable;
int *Rnumrolled;
int *CheckNumber;



//

int main ()

{
  BingoTable=(int*)malloc(sizeof(int)*4*5);
  CheckNumber=(int*)calloc(5,sizeof(int));
  Rnumrolled=(int*)calloc(100,sizeof(int));

  Header();

  seeding();

  BingoSheet(BingoTable,CheckNumber);

  CheckMatrice(BingoTable,CheckNumber);

  PrintMatrice(BingoTable);

  play(BingoTable,Rnumrolled);

  free(BingoTable);
  free(CheckNumber);
  free(Rnumrolled);

  return 0;

}


//    SDL_CreateWindowAndRenderer(800, 800, SDL_WINDOW_OPENGL, &window, &renderer);
