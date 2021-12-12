#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
  double temp;
  int s;
  for (int r = 0; r < mat->r-1; r++){
    if (mat->data[r][r] == 0) return 1;

    for (int c = r+1; c < mat->c; c++){
      temp = mat->data[c][r] / mat->data[r][r];
      for (s = 0; s < mat->c; s++){
        mat->data[c][s] =  mat->data[c][s] - temp*mat->data[r][s];
      }
      b->data[c][0] = b->data[c][0] -  temp*b->data[r][0];
    }
  }
  return 0;
}
