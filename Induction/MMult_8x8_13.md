# Optimization_8x8_13
Copy the contents of file `MMult_8x8_12.c` into a file named `MMult_8x8_13.c` and change the contents:

from
```C
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
```
to
```C
void InnerKernel(int m, int n, int k, double* a, int lda, double* b, int ldb, double* c, int ldc){
	int i, j;
	double packedA[m * k];	
	for(j = 0; j < n; j += 8){
		for(i = 0; i < m; i += 8){
			if(j == 0){
				PackMatrixA(k, &A(i, 0), lda, &packedA[i * k]);
			}
			AddDot8x8(k, &packedA[i * k], 8, &B(0, j), ldb, &C(i, j), ldc);
		}
	}
}
```
Based on MMult_4x4_12.c, the main change is to add a conditional statement that allows the InnerKernel loop to use the version already stored in the array for computation after the first iteration.

This time the performance graph will look something like:

![compare MMult_8x8_12 with MMult_8x8_13](picturer/compare_MMult_8x8_12_MMult_8x8_13.png)

You can see that the performance has exceeded the performance of the program without packaging A.

This modification eliminates the repackaging of A blocks by adding a conditional statement, thus reducing the overhead of loading data and improving performance.
