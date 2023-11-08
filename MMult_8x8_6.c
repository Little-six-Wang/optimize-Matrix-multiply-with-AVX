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
			a_0p_reg, a_1p_reg, a_2p_reg, a_3p_reg, a_4p_reg, a_5p_reg, a_6p_reg, a_7p_reg;
	
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
		
	for(p = 0; p < k; p++){
		a_0p_reg = A(0, p);
		a_1p_reg = A(1, p);
		a_2p_reg = A(2, p);
		a_3p_reg = A(3, p);
		a_4p_reg = A(4, p);
		a_5p_reg = A(5, p);
		a_6p_reg = A(6, p);
		a_7p_reg = A(7, p);

		c_00_reg += a_0p_reg * B(p, 0);
		c_01_reg += a_0p_reg * B(p, 1);
		c_02_reg += a_0p_reg * B(p, 2);
		c_03_reg += a_0p_reg * B(p, 3);
		c_04_reg += a_0p_reg * B(p, 4);
		c_05_reg += a_0p_reg * B(p, 5);
		c_06_reg += a_0p_reg * B(p, 6);
		c_07_reg += a_0p_reg * B(p, 7);

		c_10_reg += a_1p_reg * B(p, 0);
		c_11_reg += a_1p_reg * B(p, 1);
		c_12_reg += a_1p_reg * B(p, 2);
		c_13_reg += a_1p_reg * B(p, 3);
		c_14_reg += a_1p_reg * B(p, 4);
		c_15_reg += a_1p_reg * B(p, 5);
		c_16_reg += a_1p_reg * B(p, 6);
		c_17_reg += a_1p_reg * B(p, 7);

		c_20_reg += a_2p_reg * B(p, 0);
		c_21_reg += a_2p_reg * B(p, 1);
		c_22_reg += a_2p_reg * B(p, 2);
		c_23_reg += a_2p_reg * B(p, 3);
		c_24_reg += a_2p_reg * B(p, 4);
		c_25_reg += a_2p_reg * B(p, 5);
		c_26_reg += a_2p_reg * B(p, 6);
		c_27_reg += a_2p_reg * B(p, 7);

		c_30_reg += a_3p_reg * B(p, 0);
		c_31_reg += a_3p_reg * B(p, 1);
		c_32_reg += a_3p_reg * B(p, 2);
		c_33_reg += a_3p_reg * B(p, 3);
		c_34_reg += a_3p_reg * B(p, 4);
		c_35_reg += a_3p_reg * B(p, 5);
		c_36_reg += a_3p_reg * B(p, 6);
		c_37_reg += a_3p_reg * B(p, 7);

		c_40_reg += a_4p_reg * B(p, 0);
		c_41_reg += a_4p_reg * B(p, 1);
		c_42_reg += a_4p_reg * B(p, 2);
		c_43_reg += a_4p_reg * B(p, 3);
		c_44_reg += a_4p_reg * B(p, 4);
		c_45_reg += a_4p_reg * B(p, 5);
		c_46_reg += a_4p_reg * B(p, 6);
		c_47_reg += a_4p_reg * B(p, 7);

		c_50_reg += a_5p_reg * B(p, 0);
		c_51_reg += a_5p_reg * B(p, 1);
		c_52_reg += a_5p_reg * B(p, 2);
		c_53_reg += a_5p_reg * B(p, 3);
		c_54_reg += a_5p_reg * B(p, 4);
		c_55_reg += a_5p_reg * B(p, 5);
		c_56_reg += a_5p_reg * B(p, 6);
		c_57_reg += a_5p_reg * B(p, 7);

		c_60_reg += a_6p_reg * B(p, 0);
		c_61_reg += a_6p_reg * B(p, 1);
		c_62_reg += a_6p_reg * B(p, 2);
		c_63_reg += a_6p_reg * B(p, 3);
		c_64_reg += a_6p_reg * B(p, 4);
		c_65_reg += a_6p_reg * B(p, 5);
		c_66_reg += a_6p_reg * B(p, 6);
		c_67_reg += a_6p_reg * B(p, 7);

		c_70_reg += a_7p_reg * B(p, 0);
		c_71_reg += a_7p_reg * B(p, 1);
		c_72_reg += a_7p_reg * B(p, 2);
		c_73_reg += a_7p_reg * B(p, 3);
		c_74_reg += a_7p_reg * B(p, 4);
		c_75_reg += a_7p_reg * B(p, 5);
		c_76_reg += a_7p_reg * B(p, 6);
		c_77_reg += a_7p_reg * B(p, 7);
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
