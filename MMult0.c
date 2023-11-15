#define A(i, j) a[(j) * lda + (i)]
#define B(i, j) b[(j) * ldb + (i)]
#define C(i, j) c[(j) * ldc + (i)]

void MY_MMult(int m, int n, int k, double* a, int lda, double* b, int ldb,
		double* c, int ldc){
	int i, j, p;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			for(p = 0; p < k; p++){
				C(i, j) = C(i, j) + A(i, p) * B(p, j);
			}
		}
	}
}
