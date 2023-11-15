#define A(i, j) a[(j) * lda + (i)]
#define B(i, j) b[(j) * ldb + (i)]
#define C(i, j) c[(j) * ldc + (i)]
void AddDot(int, double*, int, double*, double*);

void MY_MMult(int m, int n, int k, double* a, int lda, double* b, int ldb, double* c, int ldc) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			AddDot(k, &A(i, 0), lda, &B(0, j), &C(i, j));
		}
	}
}

#define X(i) x[(i) * incx]

void AddDot(int k, double* x, int incx, double* y, double* gamma) {
	int p;
	for (p = 0; p < k; p++) {
		*gamma += X(p) * y[p];
	}
}
