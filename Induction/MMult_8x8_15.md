# Optimization_8x8_14
Copy the contents of file `MMult_8x8_14.c` into a file named `MMult_8x8_15.c` and change the contents:

from
```C
void MY_MMult(int m, int n, int k, double* a, int lda, double* b, int ldb, double* c, int ldc) {
	int p, i, pb, ib;
	for (p = 0; p < n; p += kc) {
		pb = min((n - p), kc);
		for (i = 0; i < m; i += mc) {
			ib = min((m - i), mc);
			InnerKernel(ib, n, pb, &A(i, p), lda, &B(p, 0), ldb, &C(i, 0), ldc);
		}
	}
}

void InnerKernel(int m, int n, int k, double* a, int lda, double* b, int ldb, double* c, int ldc){
	int i, j;
	double packedA[m * k], packedB[n * k];
	for(j = 0; j < n; j += 8){
		PackMatrixB(k, &B(0, j), ldb, &packedB[j * k]); //n * kc
		for(i = 0; i < m; i += 8){
			if(j == 0){
				PackMatrixA(k, &A(i, 0), lda, &packedA[i * k]); //mc * kc
			}
			AddDot8x8(k, &packedA[i * k], &packedB[j * k], &C(i, j), ldc);
		}
	}
}
```
to
```C
#define nb 1000

void MY_MMult(int m, int n, int k, double* a, int lda, double* b, int ldb, double* c, int ldc) {
	int p, i, pb, ib;
	for (p = 0; p < n; p += kc) {
		pb = min((n - p), kc);
		for (i = 0; i < m; i += mc) {
			ib = min((m - i), mc);
			InnerKernel(ib, n, pb, &A(i, p), lda, &B(p, 0), ldb, &C(i, 0), ldc, i == 0);
		}
	}
}

void InnerKernel(int m, int n, int k, double* a, int lda, double* b, int ldb, double* c, int ldc,
		int first_time){
	int i, j;
	double packedA[m * k];
	static double packedB[nb * kc]; /*Static variables are used because the numbers in packedB will still 		be used in the next loop. If static variables are not used, the elements in packedB will be 			reset in the next loop, resulting in an error.*/
	for(j = 0; j < n; j += 8){
		if(first_time){
			PackMatrixB(k, &B(0, j), ldb, &packedB[j * k]); //n * kc
		}
		for(i = 0; i < m; i += 8){
			if(j == 0){
				PackMatrixA(k, &A(i, 0), lda, &packedA[i * k]); //mc * kc
			}
			AddDot8x8(k, &packedA[i * k], &packedB[j * k], &C(i, j), ldc);
		}
	}
}
```
Modified on the basis of MMult_4x4_14.c, this modification is mainly to add a flag and a conditional statement to avoid the B block being repackaged.

This time the performance graph will look something like:

![compare MMult_8x8_14 with MMult_8x8_15](picturer/compare_MMult_8x8_14_MMult_8x8_15.png)

You can see an improvement in performance.
