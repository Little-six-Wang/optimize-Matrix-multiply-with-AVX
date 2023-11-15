# Optimization_8x8_3
Copy the contents of file `MMult_8x8_2.c` into a file named `MMult_8x8_3.c` and change the contents:

from
```C
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
			
	AddDot(k, &A(0, 0), lda, &B(0, 0), &C(0, 0));
	AddDot(k, &A(0, 0), lda, &B(0, 1), &C(0, 1));
	AddDot(k, &A(0, 0), lda, &B(0, 2), &C(0, 2));
	AddDot(k, &A(0, 0), lda, &B(0, 3), &C(0, 3));
	AddDot(k, &A(0, 0), lda, &B(0, 4), &C(0, 4));
	AddDot(k, &A(0, 0), lda, &B(0, 5), &C(0, 5));
	AddDot(k, &A(0, 0), lda, &B(0, 6), &C(0, 6));
	AddDot(k, &A(0, 0), lda, &B(0, 7), &C(0, 7));

	AddDot(k, &A(1, 0), lda, &B(0, 0), &C(1, 0));
	AddDot(k, &A(1, 0), lda, &B(0, 1), &C(1, 1));
	AddDot(k, &A(1, 0), lda, &B(0, 2), &C(1, 2));
	AddDot(k, &A(1, 0), lda, &B(0, 3), &C(1, 3));
	AddDot(k, &A(1, 0), lda, &B(0, 4), &C(1, 4));
	AddDot(k, &A(1, 0), lda, &B(0, 5), &C(1, 5));
	AddDot(k, &A(1, 0), lda, &B(0, 6), &C(1, 6));
	AddDot(k, &A(1, 0), lda, &B(0, 7), &C(1, 7));

	AddDot(k, &A(2, 0), lda, &B(0, 0), &C(2, 0));
	AddDot(k, &A(2, 0), lda, &B(0, 1), &C(2, 1));
	AddDot(k, &A(2, 0), lda, &B(0, 2), &C(2, 2));
	AddDot(k, &A(2, 0), lda, &B(0, 3), &C(2, 3));
	AddDot(k, &A(2, 0), lda, &B(0, 4), &C(2, 4));
	AddDot(k, &A(2, 0), lda, &B(0, 5), &C(2, 5));
	AddDot(k, &A(2, 0), lda, &B(0, 6), &C(2, 6));
	AddDot(k, &A(2, 0), lda, &B(0, 7), &C(2, 7));

	AddDot(k, &A(3, 0), lda, &B(0, 0), &C(3, 0));
	AddDot(k, &A(3, 0), lda, &B(0, 1), &C(3, 1));
	AddDot(k, &A(3, 0), lda, &B(0, 2), &C(3, 2));
	AddDot(k, &A(3, 0), lda, &B(0, 3), &C(3, 3));
	AddDot(k, &A(3, 0), lda, &B(0, 4), &C(3, 4));
	AddDot(k, &A(3, 0), lda, &B(0, 5), &C(3, 5));
	AddDot(k, &A(3, 0), lda, &B(0, 6), &C(3, 6));
	AddDot(k, &A(3, 0), lda, &B(0, 7), &C(3, 7));

	AddDot(k, &A(4, 0), lda, &B(0, 0), &C(4, 0));
	AddDot(k, &A(4, 0), lda, &B(0, 1), &C(4, 1));
	AddDot(k, &A(4, 0), lda, &B(0, 2), &C(4, 2));
	AddDot(k, &A(4, 0), lda, &B(0, 3), &C(4, 3));
	AddDot(k, &A(4, 0), lda, &B(0, 4), &C(4, 4));
	AddDot(k, &A(4, 0), lda, &B(0, 5), &C(4, 5));
	AddDot(k, &A(4, 0), lda, &B(0, 6), &C(4, 6));
	AddDot(k, &A(4, 0), lda, &B(0, 7), &C(4, 7));

	AddDot(k, &A(5, 0), lda, &B(0, 0), &C(5, 0));
	AddDot(k, &A(5, 0), lda, &B(0, 1), &C(5, 1));
	AddDot(k, &A(5, 0), lda, &B(0, 2), &C(5, 2));
	AddDot(k, &A(5, 0), lda, &B(0, 3), &C(5, 3));
	AddDot(k, &A(5, 0), lda, &B(0, 4), &C(5, 4));
	AddDot(k, &A(5, 0), lda, &B(0, 5), &C(5, 5));
	AddDot(k, &A(5, 0), lda, &B(0, 6), &C(5, 6));
	AddDot(k, &A(5, 0), lda, &B(0, 7), &C(5, 7));

	AddDot(k, &A(6, 0), lda, &B(0, 0), &C(6, 0));
	AddDot(k, &A(6, 0), lda, &B(0, 1), &C(6, 1));
	AddDot(k, &A(6, 0), lda, &B(0, 2), &C(6, 2));
	AddDot(k, &A(6, 0), lda, &B(0, 3), &C(6, 3));
	AddDot(k, &A(6, 0), lda, &B(0, 4), &C(6, 4));
	AddDot(k, &A(6, 0), lda, &B(0, 5), &C(6, 5));
	AddDot(k, &A(6, 0), lda, &B(0, 6), &C(6, 6));
	AddDot(k, &A(6, 0), lda, &B(0, 7), &C(6, 7));

	AddDot(k, &A(7, 0), lda, &B(0, 0), &C(7, 0));
	AddDot(k, &A(7, 0), lda, &B(0, 1), &C(7, 1));
	AddDot(k, &A(7, 0), lda, &B(0, 2), &C(7, 2));
	AddDot(k, &A(7, 0), lda, &B(0, 3), &C(7, 3));
	AddDot(k, &A(7, 0), lda, &B(0, 4), &C(7, 4));
	AddDot(k, &A(7, 0), lda, &B(0, 5), &C(7, 5));
	AddDot(k, &A(7, 0), lda, &B(0, 6), &C(7, 6));
	AddDot(k, &A(7, 0), lda, &B(0, 7), &C(7, 7));
}

#define X(i) x[(i) * incx]

void AddDot(int k, double* x, int incx, double* y, double* gamma) {
	int p;
	for (p = 0; p < k; p++) {
		*gamma += X(p) * y[p];
	}
}
```
Based on `MMult_8x8_2.c`, the modification is mainly to put the 64 `AddDot` subroutines in `MMult_8x8_2.c` into the `AddDot8x8` subroutine, so that the subroutine calculates 64 inner products at one time.

This time the performance graph will look something like:

![compare MMult_8x8_2 with MMult_8x8_3](picturer/compare_MMult_8x8_2_MMult_8x8_3.png)

You can see little improvement in performance.

