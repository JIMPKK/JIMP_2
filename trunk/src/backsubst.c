#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				if (mat->c != mat->r || mat->r != b->r || mat->r != x->r || b->c != 1 || x->c != 1) return 2;
				if (mat->data[mat->r-1][mat->c-1] == 0) return 1;
				x->data[b->r-1][0] = b->data[b->r-1][0]/mat->data[mat->r-1][mat->c-1];

				for (int r = b->r - 2; r >= 0; r--){
					x->data[r][0] = b->data[r][0];
					for (int c = b->r - 1; c > r; c--)
						x->data[r][0] = x->data[r][0] - x->data[c][0]*mat->data[r][c];
					if (mat->data[mat->r-1][mat->c-1] == 0) return 1;
					x->data[r][0] = x->data[r][0]/mat->data[r][r];
				}
				return 0;
}
/*					 PRZYKLAD
				[a11 a12 a13] [x1] = [b1] Tutaj tak: x1 = (b1 - a12*x2 - a13*x3)/a11
				[ 0  a22 a23] [x2] = [b2] Tutaj robisz tak: x22 = (b2 - x3*a23)/a22 
				[ 0   0  a33] [x3] = [b3] Tutaj masz poza petlami od razu przepisanie x3 = b3/a33
				1. Zaczynasz od konca
				2. Dla danego wiersza wykorzystujesz KAZDE wczesniej wyliczone x, 
					czyli dla x22, bedziesz uzywal wyliczone x33 z macierzy kolumnowej x.
*/