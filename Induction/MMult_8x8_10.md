# Optimization_8x8_10
Copy the contents of file `MMult_8x8_9.c` into a file named `MMult_8x8_10.c` and change the contents:

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
	int p;
	register double c_00_reg, c_01_reg, c_02_reg, c_03_reg, c_04_reg, c_05_reg, c_06_reg, c_07_reg,
			c_10_reg, c_11_reg, c_12_reg, c_13_reg, c_14_reg, c_15_reg, c_16_reg, c_17_reg,
			c_20_reg, c_21_reg, c_22_reg, c_23_reg, c_24_reg, c_25_reg, c_26_reg, c_27_reg,
			c_30_reg, c_31_reg, c_32_reg, c_33_reg, c_34_reg, c_35_reg, c_36_reg, c_37_reg,
			c_40_reg, c_41_reg, c_42_reg, c_43_reg, c_44_reg, c_45_reg, c_46_reg, c_47_reg,
			c_50_reg, c_51_reg, c_52_reg, c_53_reg, c_54_reg, c_55_reg, c_56_reg, c_57_reg,
			c_60_reg, c_61_reg, c_62_reg, c_63_reg, c_64_reg, c_65_reg, c_66_reg, c_67_reg,
			c_70_reg, c_71_reg, c_72_reg, c_73_reg, c_74_reg, c_75_reg, c_76_reg, c_77_reg,
			a_0p_reg, a_1p_reg, a_2p_reg, a_3p_reg, a_4p_reg, a_5p_reg, a_6p_reg, a_7p_reg,
			b_p0_reg, b_p1_reg, b_p2_reg, b_p3_reg, b_p4_reg, b_p5_reg, b_p6_reg, b_p7_reg;
	
	double *b_p0_pntr, *b_p1_pntr, *b_p2_pntr, *b_p3_pntr, *b_p4_pntr, *b_p5_pntr, *b_p6_pntr, *b_p7_pntr;
			
	c_00_reg = 0.0;
	c_01_reg = 0.0;
	c_02_reg = 0.0;
	c_03_reg = 0.0;
	c_04_reg = 0.0;
	c_05_reg = 0.0;
	c_06_reg = 0.0;
	c_07_reg = 0.0;
	
	c_10_reg = 0.0;
	c_11_reg = 0.0;
	c_12_reg = 0.0;
	c_13_reg = 0.0;
	c_14_reg = 0.0;
	c_15_reg = 0.0;
	c_16_reg = 0.0;
	c_17_reg = 0.0;

	c_20_reg = 0.0;
	c_21_reg = 0.0;
	c_22_reg = 0.0;
	c_23_reg = 0.0;
	c_24_reg = 0.0;
	c_25_reg = 0.0;
	c_26_reg = 0.0;
	c_27_reg = 0.0;

	c_30_reg = 0.0;
	c_31_reg = 0.0;
	c_32_reg = 0.0;
	c_33_reg = 0.0;
	c_34_reg = 0.0;
	c_35_reg = 0.0;
	c_36_reg = 0.0;
	c_37_reg = 0.0;

	c_40_reg = 0.0;
	c_41_reg = 0.0;
	c_42_reg = 0.0;
	c_43_reg = 0.0;
	c_44_reg = 0.0;
	c_45_reg = 0.0;
	c_46_reg = 0.0;
	c_47_reg = 0.0;

	c_50_reg = 0.0;
	c_51_reg = 0.0;
	c_52_reg = 0.0;
	c_53_reg = 0.0;
	c_54_reg = 0.0;
	c_55_reg = 0.0;
	c_56_reg = 0.0;
	c_57_reg = 0.0;

	c_60_reg = 0.0;
	c_61_reg = 0.0;
	c_62_reg = 0.0;
	c_63_reg = 0.0;
	c_64_reg = 0.0;
	c_65_reg = 0.0;
	c_66_reg = 0.0;
	c_67_reg = 0.0;

	c_70_reg = 0.0;
	c_71_reg = 0.0;
	c_72_reg = 0.0;
	c_73_reg = 0.0;
	c_74_reg = 0.0;
	c_75_reg = 0.0;
	c_76_reg = 0.0;
	c_77_reg = 0.0;

	b_p0_pntr = &B(0, 0);
	b_p1_pntr = &B(0, 1);
	b_p2_pntr = &B(0, 2);
	b_p3_pntr = &B(0, 3);
	b_p4_pntr = &B(0, 4);
	b_p5_pntr = &B(0, 5);
	b_p6_pntr = &B(0, 6);
	b_p7_pntr = &B(0, 7);
		
	for(p = 0; p < k; p++){
		a_0p_reg = A(0, p);
		a_1p_reg = A(1, p);
		a_2p_reg = A(2, p);
		a_3p_reg = A(3, p);
		a_4p_reg = A(4, p);
		a_5p_reg = A(5, p);
		a_6p_reg = A(6, p);
		a_7p_reg = A(7, p);
		
		b_p0_reg = *b_p0_pntr++;
		b_p1_reg = *b_p1_pntr++;
		b_p2_reg = *b_p2_pntr++;
		b_p3_reg = *b_p3_pntr++;
		b_p4_reg = *b_p4_pntr++;
		b_p5_reg = *b_p5_pntr++;
		b_p6_reg = *b_p6_pntr++;
		b_p7_reg = *b_p7_pntr++;

		c_00_reg += a_0p_reg * b_p0_reg;
		c_10_reg += a_1p_reg * b_p0_reg;
		c_20_reg += a_2p_reg * b_p0_reg;
		c_30_reg += a_3p_reg * b_p0_reg;

		c_01_reg += a_0p_reg * b_p1_reg;
		c_11_reg += a_1p_reg * b_p1_reg;
		c_21_reg += a_2p_reg * b_p1_reg;
		c_31_reg += a_3p_reg * b_p1_reg;

		c_02_reg += a_0p_reg * b_p2_reg;
		c_12_reg += a_1p_reg * b_p2_reg;
		c_22_reg += a_2p_reg * b_p2_reg;
		c_32_reg += a_3p_reg * b_p2_reg;

		c_03_reg += a_0p_reg * b_p3_reg;
		c_13_reg += a_1p_reg * b_p3_reg;
		c_23_reg += a_2p_reg * b_p3_reg;
		c_33_reg += a_3p_reg * b_p3_reg;

		c_04_reg += a_0p_reg * b_p4_reg;
		c_14_reg += a_1p_reg * b_p4_reg;
		c_24_reg += a_2p_reg * b_p4_reg;
		c_34_reg += a_3p_reg * b_p4_reg;

		c_05_reg += a_0p_reg * b_p5_reg;
		c_15_reg += a_1p_reg * b_p5_reg;
		c_25_reg += a_2p_reg * b_p5_reg;
		c_35_reg += a_3p_reg * b_p5_reg;

		c_06_reg += a_0p_reg * b_p6_reg;
		c_16_reg += a_1p_reg * b_p6_reg;
		c_26_reg += a_2p_reg * b_p6_reg;
		c_36_reg += a_3p_reg * b_p6_reg;

		c_07_reg += a_0p_reg * b_p7_reg;
		c_17_reg += a_1p_reg * b_p7_reg;
		c_27_reg += a_2p_reg * b_p7_reg;
		c_37_reg += a_3p_reg * b_p7_reg;

		c_40_reg += a_4p_reg * b_p0_reg;
		c_50_reg += a_5p_reg * b_p0_reg;
		c_60_reg += a_6p_reg * b_p0_reg;
		c_70_reg += a_7p_reg * b_p0_reg;

		c_41_reg += a_4p_reg * b_p1_reg;
		c_51_reg += a_5p_reg * b_p1_reg;
		c_61_reg += a_6p_reg * b_p1_reg;
		c_71_reg += a_7p_reg * b_p1_reg;

		c_42_reg += a_4p_reg * b_p2_reg;
		c_52_reg += a_5p_reg * b_p2_reg;
		c_62_reg += a_6p_reg * b_p2_reg;
		c_72_reg += a_7p_reg * b_p2_reg;

		c_43_reg += a_4p_reg * b_p3_reg;
		c_53_reg += a_5p_reg * b_p3_reg;
		c_63_reg += a_6p_reg * b_p3_reg;
		c_73_reg += a_7p_reg * b_p3_reg;

		c_44_reg += a_4p_reg * b_p4_reg;
		c_54_reg += a_5p_reg * b_p4_reg;
		c_64_reg += a_6p_reg * b_p4_reg;
		c_74_reg += a_7p_reg * b_p4_reg;

		c_45_reg += a_4p_reg * b_p5_reg;
		c_55_reg += a_5p_reg * b_p5_reg;
		c_65_reg += a_6p_reg * b_p5_reg;
		c_75_reg += a_7p_reg * b_p5_reg;

		c_46_reg += a_4p_reg * b_p6_reg;
		c_56_reg += a_5p_reg * b_p6_reg;
		c_66_reg += a_6p_reg * b_p6_reg;
		c_76_reg += a_7p_reg * b_p6_reg;

		c_47_reg += a_4p_reg * b_p7_reg;
		c_57_reg += a_5p_reg * b_p7_reg;
		c_67_reg += a_6p_reg * b_p7_reg;
		c_77_reg += a_7p_reg * b_p7_reg;
	}

	C(0, 0) += c_00_reg;
	C(0, 1) += c_01_reg;
	C(0, 2) += c_02_reg;
	C(0, 3) += c_03_reg;
	C(0, 4) += c_04_reg;
	C(0, 5) += c_05_reg;
	C(0, 6) += c_06_reg;
	C(0, 7) += c_07_reg;

	C(1, 0) += c_10_reg;
	C(1, 1) += c_11_reg;
	C(1, 2) += c_12_reg;
	C(1, 3) += c_13_reg;
	C(1, 4) += c_14_reg;
	C(1, 5) += c_15_reg;
	C(1, 6) += c_16_reg;
	C(1, 7) += c_17_reg;

	C(2, 0) += c_20_reg;
	C(2, 1) += c_21_reg;
	C(2, 2) += c_22_reg;
	C(2, 3) += c_23_reg;
	C(2, 4) += c_24_reg;
	C(2, 5) += c_25_reg;
	C(2, 6) += c_26_reg;
	C(2, 7) += c_27_reg;

	C(3, 0) += c_30_reg;
	C(3, 1) += c_31_reg;
	C(3, 2) += c_32_reg;
	C(3, 3) += c_33_reg;
	C(3, 4) += c_34_reg;
	C(3, 5) += c_35_reg;
	C(3, 6) += c_36_reg;
	C(3, 7) += c_37_reg;

	C(4, 0) += c_40_reg;
	C(4, 1) += c_41_reg;
	C(4, 2) += c_42_reg;
	C(4, 3) += c_43_reg;
	C(4, 4) += c_44_reg;
	C(4, 5) += c_45_reg;
	C(4, 6) += c_46_reg;
	C(4, 7) += c_47_reg;

	C(5, 0) += c_50_reg;
	C(5, 1) += c_51_reg;
	C(5, 2) += c_52_reg;
	C(5, 3) += c_53_reg;
	C(5, 4) += c_54_reg;
	C(5, 5) += c_55_reg;
	C(5, 6) += c_56_reg;
	C(5, 7) += c_57_reg;

	C(6, 0) += c_60_reg;
	C(6, 1) += c_61_reg;
	C(6, 2) += c_62_reg;
	C(6, 3) += c_63_reg;
	C(6, 4) += c_64_reg;
	C(6, 5) += c_65_reg;
	C(6, 6) += c_66_reg;
	C(6, 7) += c_67_reg;

	C(7, 0) += c_70_reg;
	C(7, 1) += c_71_reg;
	C(7, 2) += c_72_reg;
	C(7, 3) += c_73_reg;
	C(7, 4) += c_74_reg;
	C(7, 5) += c_75_reg;
	C(7, 6) += c_76_reg;
	C(7, 7) += c_77_reg;	
}
```
to
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

#include<immintrin.h> //AVX

typedef union{
	__m256d v;
	double d[4];
}v4df_t;

void AddDot8x8(int k, double* a, int lda, double* b, int ldb, double* c, int ldc){
	int p;
	v4df_t c_00_c_10_c_20_c_30_vreg, c_01_c_11_c_21_c_31_vreg,
		c_02_c_12_c_22_c_32_vreg, c_03_c_13_c_23_c_33_vreg,
		c_04_c_14_c_24_c_34_vreg, c_05_c_15_c_25_c_35_vreg,
		c_06_c_16_c_26_c_36_vreg, c_07_c_17_c_27_c_37_vreg,
		c_40_c_50_c_60_c_70_vreg, c_41_c_51_c_61_c_71_vreg,
		c_42_c_52_c_62_c_72_vreg, c_43_c_53_c_63_c_73_vreg,
		c_44_c_54_c_64_c_74_vreg, c_45_c_55_c_65_c_75_vreg,
		c_46_c_56_c_66_c_76_vreg, c_47_c_57_c_67_c_77_vreg,
		a_0p_1p_2p_3p_vreg, a_4p_5p_6p_7p_vreg,
		b_p0_vreg, b_p1_vreg, b_p2_vreg, b_p3_vreg,
		b_p4_vreg, b_p5_vreg, b_p6_vreg, b_p7_vreg;
	
	double *b_p0_pntr, *b_p1_pntr, *b_p2_pntr, *b_p3_pntr, *b_p4_pntr, *b_p5_pntr, *b_p6_pntr, *b_p7_pntr;
	
	c_00_c_10_c_20_c_30_vreg.v = _mm256_setzero_pd();
	c_01_c_11_c_21_c_31_vreg.v = _mm256_setzero_pd();
	c_02_c_12_c_22_c_32_vreg.v = _mm256_setzero_pd();
	c_03_c_13_c_23_c_33_vreg.v = _mm256_setzero_pd();
	c_04_c_14_c_24_c_34_vreg.v = _mm256_setzero_pd();
	c_05_c_15_c_25_c_35_vreg.v = _mm256_setzero_pd();
	c_06_c_16_c_26_c_36_vreg.v = _mm256_setzero_pd();
	c_07_c_17_c_27_c_37_vreg.v = _mm256_setzero_pd();

	c_40_c_50_c_60_c_70_vreg.v = _mm256_setzero_pd();
	c_41_c_51_c_61_c_71_vreg.v = _mm256_setzero_pd();
	c_42_c_52_c_62_c_72_vreg.v = _mm256_setzero_pd();
	c_43_c_53_c_63_c_73_vreg.v = _mm256_setzero_pd();
	c_44_c_54_c_64_c_74_vreg.v = _mm256_setzero_pd();
	c_45_c_55_c_65_c_75_vreg.v = _mm256_setzero_pd();
	c_46_c_56_c_66_c_76_vreg.v = _mm256_setzero_pd();
	c_47_c_57_c_67_c_77_vreg.v = _mm256_setzero_pd();


	b_p0_pntr = &B(0, 0);
	b_p1_pntr = &B(0, 1);
	b_p2_pntr = &B(0, 2);
	b_p3_pntr = &B(0, 3);
	b_p4_pntr = &B(0, 4);
	b_p5_pntr = &B(0, 5);
	b_p6_pntr = &B(0, 6);
	b_p7_pntr = &B(0, 7);
		
	for(p = 0; p < k; p++){
		a_0p_1p_2p_3p_vreg.v = _mm256_loadu_pd((double*)&A(0, p));
		a_4p_5p_6p_7p_vreg.v = _mm256_loadu_pd((double*)&A(4, p));

		b_p0_vreg.v = _mm256_set1_pd((double)*b_p0_pntr++);
		b_p1_vreg.v = _mm256_set1_pd((double)*b_p1_pntr++);
		b_p2_vreg.v = _mm256_set1_pd((double)*b_p2_pntr++);
		b_p3_vreg.v = _mm256_set1_pd((double)*b_p3_pntr++);
		b_p4_vreg.v = _mm256_set1_pd((double)*b_p4_pntr++);
		b_p5_vreg.v = _mm256_set1_pd((double)*b_p5_pntr++);
		b_p6_vreg.v = _mm256_set1_pd((double)*b_p6_pntr++);
		b_p7_vreg.v = _mm256_set1_pd((double)*b_p7_pntr++);

		c_00_c_10_c_20_c_30_vreg.v += a_0p_1p_2p_3p_vreg.v * b_p0_vreg.v;
		c_01_c_11_c_21_c_31_vreg.v += a_0p_1p_2p_3p_vreg.v * b_p1_vreg.v;
		c_02_c_12_c_22_c_32_vreg.v += a_0p_1p_2p_3p_vreg.v * b_p2_vreg.v;
		c_03_c_13_c_23_c_33_vreg.v += a_0p_1p_2p_3p_vreg.v * b_p3_vreg.v;
		c_04_c_14_c_24_c_34_vreg.v += a_0p_1p_2p_3p_vreg.v * b_p4_vreg.v;
		c_05_c_15_c_25_c_35_vreg.v += a_0p_1p_2p_3p_vreg.v * b_p5_vreg.v;
		c_06_c_16_c_26_c_36_vreg.v += a_0p_1p_2p_3p_vreg.v * b_p6_vreg.v;
		c_07_c_17_c_27_c_37_vreg.v += a_0p_1p_2p_3p_vreg.v * b_p7_vreg.v;

		c_40_c_50_c_60_c_70_vreg.v += a_4p_5p_6p_7p_vreg.v * b_p0_vreg.v;
		c_41_c_51_c_61_c_71_vreg.v += a_4p_5p_6p_7p_vreg.v * b_p1_vreg.v;
		c_42_c_52_c_62_c_72_vreg.v += a_4p_5p_6p_7p_vreg.v * b_p2_vreg.v;
		c_43_c_53_c_63_c_73_vreg.v += a_4p_5p_6p_7p_vreg.v * b_p3_vreg.v;
		c_44_c_54_c_64_c_74_vreg.v += a_4p_5p_6p_7p_vreg.v * b_p4_vreg.v;
		c_45_c_55_c_65_c_75_vreg.v += a_4p_5p_6p_7p_vreg.v * b_p5_vreg.v;
		c_46_c_56_c_66_c_76_vreg.v += a_4p_5p_6p_7p_vreg.v * b_p6_vreg.v;
		c_47_c_57_c_67_c_77_vreg.v += a_4p_5p_6p_7p_vreg.v * b_p7_vreg.v;
	}

	C(0, 0) += c_00_c_10_c_20_c_30_vreg.d[0];
	C(0, 1) += c_01_c_11_c_21_c_31_vreg.d[0];
	C(0, 2) += c_02_c_12_c_22_c_32_vreg.d[0];
	C(0, 3) += c_03_c_13_c_23_c_33_vreg.d[0];
	C(0, 4) += c_04_c_14_c_24_c_34_vreg.d[0];
	C(0, 5) += c_05_c_15_c_25_c_35_vreg.d[0];
	C(0, 6) += c_06_c_16_c_26_c_36_vreg.d[0];
	C(0, 7) += c_07_c_17_c_27_c_37_vreg.d[0];

	C(1, 0) += c_00_c_10_c_20_c_30_vreg.d[1];
	C(1, 1) += c_01_c_11_c_21_c_31_vreg.d[1];
	C(1, 2) += c_02_c_12_c_22_c_32_vreg.d[1];
	C(1, 3) += c_03_c_13_c_23_c_33_vreg.d[1];
	C(1, 4) += c_04_c_14_c_24_c_34_vreg.d[1];
	C(1, 5) += c_05_c_15_c_25_c_35_vreg.d[1];
	C(1, 6) += c_06_c_16_c_26_c_36_vreg.d[1];
	C(1, 7) += c_07_c_17_c_27_c_37_vreg.d[1];

	C(2, 0) += c_00_c_10_c_20_c_30_vreg.d[2];
	C(2, 1) += c_01_c_11_c_21_c_31_vreg.d[2];
	C(2, 2) += c_02_c_12_c_22_c_32_vreg.d[2];
	C(2, 3) += c_03_c_13_c_23_c_33_vreg.d[2];
	C(2, 4) += c_04_c_14_c_24_c_34_vreg.d[2];
	C(2, 5) += c_05_c_15_c_25_c_35_vreg.d[2];
	C(2, 6) += c_06_c_16_c_26_c_36_vreg.d[2];
	C(2, 7) += c_07_c_17_c_27_c_37_vreg.d[2];

	C(3, 0) += c_00_c_10_c_20_c_30_vreg.d[3];
	C(3, 1) += c_01_c_11_c_21_c_31_vreg.d[3];
	C(3, 2) += c_02_c_12_c_22_c_32_vreg.d[3];
	C(3, 3) += c_03_c_13_c_23_c_33_vreg.d[3];
	C(3, 4) += c_04_c_14_c_24_c_34_vreg.d[3];
	C(3, 5) += c_05_c_15_c_25_c_35_vreg.d[3];
	C(3, 6) += c_06_c_16_c_26_c_36_vreg.d[3];
	C(3, 7) += c_07_c_17_c_27_c_37_vreg.d[3];

	C(4, 0) += c_40_c_50_c_60_c_70_vreg.d[0];
	C(4, 1) += c_41_c_51_c_61_c_71_vreg.d[0];
	C(4, 2) += c_42_c_52_c_62_c_72_vreg.d[0];
	C(4, 3) += c_43_c_53_c_63_c_73_vreg.d[0];
	C(4, 4) += c_44_c_54_c_64_c_74_vreg.d[0];
	C(4, 5) += c_45_c_55_c_65_c_75_vreg.d[0];
	C(4, 6) += c_46_c_56_c_66_c_76_vreg.d[0];
	C(4, 7) += c_47_c_57_c_67_c_77_vreg.d[0];

	C(5, 0) += c_40_c_50_c_60_c_70_vreg.d[1];
	C(5, 1) += c_41_c_51_c_61_c_71_vreg.d[1];
	C(5, 2) += c_42_c_52_c_62_c_72_vreg.d[1];
	C(5, 3) += c_43_c_53_c_63_c_73_vreg.d[1];
	C(5, 4) += c_44_c_54_c_64_c_74_vreg.d[1];
	C(5, 5) += c_45_c_55_c_65_c_75_vreg.d[1];
	C(5, 6) += c_46_c_56_c_66_c_76_vreg.d[1];
	C(5, 7) += c_47_c_57_c_67_c_77_vreg.d[1];

	C(6, 0) += c_40_c_50_c_60_c_70_vreg.d[2];
	C(6, 1) += c_41_c_51_c_61_c_71_vreg.d[2];
	C(6, 2) += c_42_c_52_c_62_c_72_vreg.d[2];
	C(6, 3) += c_43_c_53_c_63_c_73_vreg.d[2];
	C(6, 4) += c_44_c_54_c_64_c_74_vreg.d[2];
	C(6, 5) += c_45_c_55_c_65_c_75_vreg.d[2];
	C(6, 6) += c_46_c_56_c_66_c_76_vreg.d[2];
	C(6, 7) += c_47_c_57_c_67_c_77_vreg.d[2];

	C(7, 0) += c_40_c_50_c_60_c_70_vreg.d[3];
	C(7, 1) += c_41_c_51_c_61_c_71_vreg.d[3];
	C(7, 2) += c_42_c_52_c_62_c_72_vreg.d[3];
	C(7, 3) += c_43_c_53_c_63_c_73_vreg.d[3];
	C(7, 4) += c_44_c_54_c_64_c_74_vreg.d[3];
	C(7, 5) += c_45_c_55_c_65_c_75_vreg.d[3];
	C(7, 6) += c_46_c_56_c_66_c_76_vreg.d[3];
	C(7, 7) += c_47_c_57_c_67_c_77_vreg.d[3];
}
```
And change the line in the `makefile`
```makefile
CFLAGS     := -O2 -Wall -msse3
```
 to
 ```makefile
 CFLAGS     := -O2 -Wall -mavx
 ```
Modified on the basis of MMult_4x4_9.c, this modification mainly uses the AVX instruction set to perform vectorization computation.

This time the performance graph will look something like:

![compare MMult_8x8_9 with MMult_8x8_10](picturer/compare_MMult_8x8_9_MMult_8x8_10.png)

You can see a big improvement in performance.

I think this is because the modified program performs vectorization calculations (i.e. SIMD), which allows for simultaneous processing of multiple data (multiplication and addition of four numbers at the same time in this optimization), which greatly speeds up the operation.
