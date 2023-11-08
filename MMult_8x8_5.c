#define A(i, j) a[(j) * lda + (i)]
#define B(i, j) b[(j) * ldb + (i)]
#define C(i, j) c[(j) * ldc + (i)]

void AddDot(int, double*, int, double*, double*);
void AddDot8x8(int, double*, int, double*, int, double*, int);

void MY_MMult(int m, int n, int k, double* a, int lda, double* b, int ldb, double* c, int ldc) {
	int i, j;
	for (i = 0; i < n; i += 8) {
		for (j = 0; j < m; j += 8) {
			AddDot8x8(k, &A(i, 0), lda, &B(0, j), ldb, &C(i, j), ldc);
		}
	}
}

void AddDot8x8(int k, double* a, int lda, double* b, int ldb, double* c, int ldc){
	int p;	
	for(p = 0; p < k; p++){
		C(0, 0) += A(0, p) * B(p, 0);
		C(0, 1) += A(0, p) * B(p, 1);
		C(0, 2) += A(0, p) * B(p, 2);
		C(0, 3) += A(0, p) * B(p, 3);
		C(0, 4) += A(0, p) * B(p, 4);
		C(0, 5) += A(0, p) * B(p, 5);
		C(0, 6) += A(0, p) * B(p, 6);
		C(0, 7) += A(0, p) * B(p, 7);

		C(1, 0) += A(1, p) * B(p, 0);
		C(1, 1) += A(1, p) * B(p, 1);
		C(1, 2) += A(1, p) * B(p, 2);
		C(1, 3) += A(1, p) * B(p, 3);
		C(1, 4) += A(1, p) * B(p, 4);
		C(1, 5) += A(1, p) * B(p, 5);
		C(1, 6) += A(1, p) * B(p, 6);
		C(1, 7) += A(1, p) * B(p, 7);

		C(2, 0) += A(2, p) * B(p, 0);
		C(2, 1) += A(2, p) * B(p, 1);
		C(2, 2) += A(2, p) * B(p, 2);
		C(2, 3) += A(2, p) * B(p, 3);
		C(2, 4) += A(2, p) * B(p, 4);
		C(2, 5) += A(2, p) * B(p, 5);
		C(2, 6) += A(2, p) * B(p, 6);
		C(2, 7) += A(2, p) * B(p, 7);

		C(3, 0) += A(3, p) * B(p, 0);
		C(3, 1) += A(3, p) * B(p, 1);
		C(3, 2) += A(3, p) * B(p, 2);
		C(3, 3) += A(3, p) * B(p, 3);
		C(3, 4) += A(3, p) * B(p, 4);
		C(3, 5) += A(3, p) * B(p, 5);
		C(3, 6) += A(3, p) * B(p, 6);
		C(3, 7) += A(3, p) * B(p, 7);

		C(4, 0) += A(4, p) * B(p, 0);
		C(4, 1) += A(4, p) * B(p, 1);
		C(4, 2) += A(4, p) * B(p, 2);
		C(4, 3) += A(4, p) * B(p, 3);
		C(4, 4) += A(4, p) * B(p, 4);
		C(4, 5) += A(4, p) * B(p, 5);
		C(4, 6) += A(4, p) * B(p, 6);
		C(4, 7) += A(4, p) * B(p, 7);

		C(5, 0) += A(5, p) * B(p, 0);
		C(5, 1) += A(5, p) * B(p, 1);
		C(5, 2) += A(5, p) * B(p, 2);
		C(5, 3) += A(5, p) * B(p, 3);
		C(5, 4) += A(5, p) * B(p, 4);
		C(5, 5) += A(5, p) * B(p, 5);
		C(5, 6) += A(5, p) * B(p, 6);
		C(5, 7) += A(5, p) * B(p, 7);

		C(6, 0) += A(6, p) * B(p, 0);
		C(6, 1) += A(6, p) * B(p, 1);
		C(6, 2) += A(6, p) * B(p, 2);
		C(6, 3) += A(6, p) * B(p, 3);
		C(6, 4) += A(6, p) * B(p, 4);
		C(6, 5) += A(6, p) * B(p, 5);
		C(6, 6) += A(6, p) * B(p, 6);
		C(6, 7) += A(6, p) * B(p, 7);

		C(7, 0) += A(7, p) * B(p, 0);
		C(7, 1) += A(7, p) * B(p, 1);
		C(7, 2) += A(7, p) * B(p, 2);
		C(7, 3) += A(7, p) * B(p, 3);
		C(7, 4) += A(7, p) * B(p, 4);
		C(7, 5) += A(7, p) * B(p, 5);
		C(7, 6) += A(7, p) * B(p, 6);
		C(7, 7) += A(7, p) * B(p, 7);
	}	
}
