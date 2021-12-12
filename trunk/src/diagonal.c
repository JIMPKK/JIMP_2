#include "diagonal.h"
#include <math.h>
void element(Matrix *A, Matrix *b, int i){
    double max = fabs(A->data[i][i]);
    for (int r = 0; r < A->c; r++){
        if (fabs(A->data[r][i]) > max)
            max = A->data[r][i];
            swap(A, b, i, r);
    }
}

void swap(Matrix *mat, Matrix *b, int i, int j){
    double temp;
    for (int s = 0; s < mat->c; s++){
        temp = mat->data[i][s];
        mat->data[i][s] = mat->data[j][s];
        mat->data[j][s] = temp;
        temp = b->data[i][s];
        b->data[i][s] = b->data[j][s];
        b->data[j][s] = temp;
    }

}