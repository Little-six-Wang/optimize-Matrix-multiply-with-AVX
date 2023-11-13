# Optimization_8x8_12
Copy the contents of file `MMult_8x8_11.c` into a file named `MMult_8x8_12.c` and change the contents:

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
	for(j = 0; j < n; j += 8){
		for(i = 0; i < m; i += 8){
			AddDot8x8(k, &A(i, 0), lda, &B(0, j), ldb, &C(i, j), ldc);
		}
	}
}
```
to
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
	double packedA[m * k];	
	for(j = 0; j < n; j += 8){
		for(i = 0; i < m; i += 8){
			PackMatrixA(k, &A(i, 0), lda, &packedA[i * k]);
			AddDot8x8(k, &packedA[i * k], 8, &B(0, j), ldb, &C(i, j), ldc);
		}
	}
}

void PackMatrixA(int k, double* a, int lda, double* a_to){
	int j;
	for(j = 0; j < k; j++){
		double * a_ij_pntr = &A(0, j);
		*a_to++ = *a_ij_pntr;
		*a_to++ = *(a_ij_pntr + 1);
		*a_to++ = *(a_ij_pntr + 2);
		*a_to++ = *(a_ij_pntr + 3);
		*a_to++ = *(a_ij_pntr + 4);
		*a_to++ = *(a_ij_pntr + 5);
		*a_to++ = *(a_ij_pntr + 6);
		*a_to++ = *(a_ij_pntr + 7);
	}
}
```
Based on the modification of MMult_4x4_11.c, this modification is mainly to load the elements of A that will paThis time the performance graph will look something like:

![compare MMult_8x8_11 with MMult_8x8_12](picturer/compare_MMult_8x8_11_MMult_8x8_12.png)

You can see a slight drop in performance, and I think the reasons for this are:

The elements of A that will be involved in the calculation are put into an array, which can reduce the time overhead of reading data, and also improve the locality of the program. However, due to the repeated packaging of block A, it is not only the same as the time cost of directly reading the elements of A before optimization, but also the extra store-read data cost counteracts or even exceeds the advantage brought by the local improvement, so the overall performance is slightly lower than the last time.
