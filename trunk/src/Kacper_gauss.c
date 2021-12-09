#include<stdio.h>
// mój gauss
int main()

{
  int i, j, k, n;
  float A[20][20], c, x[10], sum = 0.0;
  printf("\nProszę podać ilość niewiadomych: ");
  scanf("%d", & n);
  printf("\nProszę podać elementy macierzy zgodnie z opisem:\n\n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= (n + 1); j++) {
      printf("A[%d][%d] : ", i, j);
      scanf("%f", & A[i][j]);
    }
  }
  for (j = 1; j <= n; j++) /* pętla, która tworzy macierz trójkątną*/ {
    for (i = 1; i <= n; i++) {
      if (i > j) {
        c = A[i][j] / A[j][j];
        for (k = 1; k <= n + 1; k++) {
          A[i][k] = A[i][k] - c * A[j][k];
        }
      }
    }
  }
  for (j = 1; j <= n+1; j++){
    for (i = 1; i <= n+1; i++){
      printf("%f ", A[j][i]);
    }
    printf("\n");
  }
}
