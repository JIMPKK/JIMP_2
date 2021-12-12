#ifndef _DIAGONAL_H
#define _DIAGONAL_H

#include "mat_io.h"

/* Wybor elementu glownego w kolumnie.
Polega to zamianie wierszy w ten sposob, aby w i-tej
iteracji eliminacji gaussa, i-tym wierszem byl wiersz,
którego i-ty element ma największy moduł sposród
innych wierszy na i-tym miejscu.
*/
void element(Matrix *mat, Matrix *b, int i);


/*
Funkcja zamienia miejscami dwa wiersze (i oraz j)
*/
void swap(Matrix *mat, Matrix *b, int i, int j);

#endif
