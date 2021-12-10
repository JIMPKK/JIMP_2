int gauss(Matrix* mat, Matrix* b, Matrix* x){
  if (mat->c != mat->r || mat->r != b->r) return 1;

  int n = x->r; // tworzymy nowy matrix
  double A[20][20];
  for (int i = 0; i <= n; i++) {
    for (int j =0; j <= n; j++) {
      A[i][j] = mat[i][j];
    }
  }
  for (int i = 0; i <= n; i++){
    int j = n+1;
    A[i][j] = b[i][j];
  }

  int n = x->r;
  for (j = 0; j <= n; j++) /* pętla, która tworzy macierz trójkątną*/ {
     for (i = 0; i <= n; i++) {
       if (i > j) {
         c = A[i][j] / A[j][j];
         for (k = 0; k <= n + 1; k++) {
           A[i][k] = A[i][k] - c * A[j][k];
         }
       }
     }
   }
   
   for (int i = 0; i <= n; i++) { // przepisanie z nowego matrixa do starych
     for (int j = 0; j <= n; j++) {
       mat[i][j] = A[i][j];
     }
   }
   for (int i = 0; i <= n; i++){
     int j = n+1;
     b[i][j] = A[i][j];
   }

   return 0;
 }
