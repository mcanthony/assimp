#include "UnitTestPCH.h"

#include <fast_atof.h>


class FastAtofTest : public ::testing::Test
{
protected:
	template <typename Real, typename AtofFunc>
	static void RunTest(AtofFunc atof_func)
	{
		const Real kEps = 1e-5;

#define TEST_CASE(NUM) EXPECT_NEAR(static_cast<Real>(NUM), atof_func(#NUM), kEps)
#define TEST_CASE_NAN(NUM) EXPECT_TRUE(std::isnan(atof_func(#NUM)))
#define TEST_CASE_INF(NUM) EXPECT_TRUE(std::isinf(atof_func(#NUM)))

		TEST_CASE(0);
		TEST_CASE(1.354);
		TEST_CASE(1054E-3);
		TEST_CASE(-1054E-3);
		TEST_CASE(-10.54E30);
		TEST_CASE(-345554.54e-5);
		TEST_CASE(-34555.534954e-5);
		TEST_CASE(-34555.534954e-5);
		TEST_CASE(549067);
		TEST_CASE(567);
		TEST_CASE(446);
		TEST_CASE(7);
		TEST_CASE(73);
		TEST_CASE(256);
		TEST_CASE(5676);
		TEST_CASE(3);
		TEST_CASE(738);
		TEST_CASE(684);
		TEST_CASE(26);
		TEST_CASE(673.678e-56);
		TEST_CASE(53);
		TEST_CASE(67);
		TEST_CASE(684);
		TEST_CASE(-5437E24);
		TEST_CASE(8);
		TEST_CASE(84);
		TEST_CASE(3);
		TEST_CASE(56733.68);
		TEST_CASE(786);
		TEST_CASE(6478);
		TEST_CASE(34563.65683598734);
		TEST_CASE(5673);
		TEST_CASE(784e-3);
		TEST_CASE(8678);
		TEST_CASE(46784);
		TEST_CASE(-54.0888e-6);
		TEST_CASE(100000e10);
		TEST_CASE(1e-307);
		TEST_CASE(0.000001e-301);
		TEST_CASE(0.0000001e-300);
		TEST_CASE(0.00000001e-299);
		TEST_CASE(1000000e-313);
		TEST_CASE(10000000e-314);
		TEST_CASE(100000000e-315);
		TEST_CASE(12.345);
		TEST_CASE(12.345e19);
		TEST_CASE(-.1e+9);
		TEST_CASE(.125);
		TEST_CASE(1e20);
		TEST_CASE(0e-19);
		TEST_CASE(400012);
		TEST_CASE(5.9e-76);
		TEST_CASE_INF(inf);
		TEST_CASE_INF(inf);
		TEST_CASE_INF(infinity);
		TEST_CASE_INF(Inf);
		TEST_CASE_INF(-Inf);
		TEST_CASE_INF(+InFiNiTy);
		TEST_CASE_NAN(NAN);
		TEST_CASE_NAN(NaN);
		TEST_CASE_NAN(nan);
		EXPECT_EQ(static_cast<Real>(6), atof_func("006"));
		EXPECT_EQ(static_cast<Real>(5.3), atof_func("5.300  "));

		/* Failing Cases:
		EXPECT_EQ(static_cast<Real>(6), atof_func("  006"));
		EXPECT_EQ(static_cast<Real>(5.3), atof_func("  5.300  "));
		TEST_CASE(-10.54E45);
		TEST_CASE(0x0A);
		TEST_CASE(0xA0);
		TEST_CASE(0x1p1023);
		TEST_CASE(0x1000p1011);
		TEST_CASE(0x1p1020);
		TEST_CASE(0x0.00001p1040);
		TEST_CASE(0x1p-1021);
		TEST_CASE(0x1000p-1033);
		TEST_CASE(0x10000p-1037);
		TEST_CASE(0x0.001p-1009);
		TEST_CASE(0x0.0001p-1005);
		TEST_CASE(0x1.4p+3);
		TEST_CASE(0xAp0);
		TEST_CASE(0x0Ap0);
		TEST_CASE(0x0.A0p8);
		TEST_CASE(0x0.50p9);
		TEST_CASE(0x0.28p10);
		TEST_CASE(0x0.14p11);
		TEST_CASE(0x0.0A0p12);
		TEST_CASE(0x0.050p13);
		TEST_CASE(0x0.028p14);
		TEST_CASE(0x0.014p15);
		TEST_CASE(0x00.00A0p16);
		TEST_CASE(0x00.0050p17);
		TEST_CASE(0x00.0028p18);
		TEST_CASE(0x00.0014p19);
		TEST_CASE(0x1p-1023);
		TEST_CASE(0x0.8p-1022);
		TEST_CASE(0x80000Ap-23);
		TEST_CASE(0x100000000000008p0);
		TEST_CASE(0x100000000000008.p0);
		TEST_CASE(0x100000000000008.00p0);
		TEST_CASE(0x10000000000000800p0);
		TEST_CASE(0x10000000000000801p0)
		*/

#undef TEST_CASE
#undef TEST_CASE_NAN
#undef TEST_CASE_INF
	}
};

struct FastAtofWrapper {
	float operator()(const char* str) { return Assimp::fast_atof(str); }
};

struct FastAtodWrapper {
	double operator()(const char* str) { return Assimp::fast_atod(str); }
};

TEST_F(FastAtofTest, FastAtof)
{
	RunTest<float>(FastAtofWrapper());
}

TEST_F(FastAtofTest, FastAtod)
{
	RunTest<double>(FastAtodWrapper());
}