# Optimization_8x8_2
Copy the contents of file `MMult0.c` into a file named `MMult_8x8_2.c` and change the contents:

from
```C
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
```

to

```C
#define A(i, j) a[(j) * lda + (i)]
#define B(i, j) b[(j) * ldb + (i)]
#define C(i, j) c[(j) * ldc + (i)]

void AddDot(int, double*, int, double*, double*);

void MY_MMult(int m, int n, int k, double* a, int lda, double* b, int ldb, double* c, int ldc) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j += 8) {
			AddDot(k, &A(i, 0), lda, &B(0, j), &C(i, j));
			AddDot(k, &A(i, 0), lda, &B(0, j + 1), &C(i, j + 1));
			AddDot(k, &A(i, 0), lda, &B(0, j + 2), &C(i, j + 2));
			AddDot(k, &A(i, 0), lda, &B(0, j + 3), &C(i, j + 3));
			AddDot(k, &A(i, 0), lda, &B(0, j + 4), &C(i, j + 4));
			AddDot(k, &A(i, 0), lda, &B(0, j + 5), &C(i, j + 5));
			AddDot(k, &A(i, 0), lda, &B(0, j + 6), &C(i, j + 6));
			AddDot(k, &A(i, 0), lda, &B(0, j + 7), &C(i, j + 7));
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
```
This time the performance graph will look something like：

![compare MMult1 with MMult_8x8_2](picture\compare_MMult0_MMult_8x8_2.png)

