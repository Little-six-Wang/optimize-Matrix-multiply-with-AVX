#define A(i, j) a[(j) * lda + (i)]
#define B(i, j) b[(j) * ldb + (i)]
#define C(i, j) c[(j) * ldc + (i)]

//block size
#define mc 256
#define kc 128
#define nb 1000

#define min(i, j)((i) < (j) ? (i) : (j))

void AddDot(int, double*, int, double*, double*);
void AddDot8x8(int, double*, double*, double*, int);
void PackMatrixA(int, double*, int, double*);
void PackMatrixB(int, double*, int, double*);
void InnerKernel(int, int, int, double*, int, double*, int, double*, int, int);



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

void PackMatrixA(int k, double* a, int lda, double* a_to){
	int j;
	for(j = 0; j < k; j++){
		double * a_ij_pntr = &A(0, j);
		*a_to = *a_ij_pntr;
		*(a_to + 1) = *(a_ij_pntr + 1);
		*(a_to + 2) = *(a_ij_pntr + 2);
		*(a_to + 3) = *(a_ij_pntr + 3);
		*(a_to + 4) = *(a_ij_pntr + 4);
		*(a_to + 5) = *(a_ij_pntr + 5);
		*(a_to + 6) = *(a_ij_pntr + 6);
		*(a_to + 7) = *(a_ij_pntr + 7);
		
		a_to += 8;
	}
}

void PackMatrixB(int k, double* b, int ldb, double* b_to){
	int j;
	double *b_i0_pntr = &B(0, 0), *b_i1_pntr = &B(0, 1), *b_i2_pntr = &B(0, 2), *b_i3_pntr = &B(0, 3),
		*b_i4_pntr = &B(0, 4), *b_i5_pntr = &B(0, 5), *b_i6_pntr = &B(0, 6), *b_i7_pntr = &B(0, 7);
	for(j = 0; j < k; j++){
		*b_to++ = *b_i0_pntr++;
		*b_to++ = *b_i1_pntr++;
		*b_to++ = *b_i2_pntr++;
		*b_to++ = *b_i3_pntr++;
		*b_to++ = *b_i4_pntr++;
		*b_to++ = *b_i5_pntr++;
		*b_to++ = *b_i6_pntr++;
		*b_to++ = *b_i7_pntr++;
	}
}

#include<immintrin.h> //AVX

typedef union{
	__m256d v;
	double d[4];
}v4df_t;

void AddDot8x8(int k, double* a, double* b, double* c, int ldc){
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
		
	for(p = 0; p < k; p++){
		a_0p_1p_2p_3p_vreg.v = _mm256_loadu_pd((double*)a);
		a_4p_5p_6p_7p_vreg.v = _mm256_loadu_pd((double*)(a + 4));
		a += 8;

		b_p0_vreg.v = _mm256_set1_pd((double)*b);
		b_p1_vreg.v = _mm256_set1_pd((double)*(b + 1));
		b_p2_vreg.v = _mm256_set1_pd((double)*(b + 2));
		b_p3_vreg.v = _mm256_set1_pd((double)*(b + 3));
		b_p4_vreg.v = _mm256_set1_pd((double)*(b + 4));
		b_p5_vreg.v = _mm256_set1_pd((double)*(b + 5));
		b_p6_vreg.v = _mm256_set1_pd((double)*(b + 6));
		b_p7_vreg.v = _mm256_set1_pd((double)*(b + 7));
		b += 8;

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
