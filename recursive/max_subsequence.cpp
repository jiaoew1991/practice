#include "common/error_code.h"
#include "common/log.h"
#include <gtest/gtest.h>

int maxSubsequence(int* sequence, int length)
{
	int tmax = 0;
	int tn = 0;
	for (int i = 0; i < length; ++i)
	{
		tn += sequence[i];
		if (tn < 0)
		{
			tn = 0;
		}
		if (tn > tmax)
		{
			tmax = tn;
		}
	}
	return tmax;
}

double maxMultipleSubseq(double* seq, int length)
{
	double tmax = 1;
	double tn = 1;
	double tun = -1;
	for (int i = 0; i < length; ++i)
	{
		if (seq[i] < 0)
		{
			double tmp = tun;
			tun = tn * seq[i];
			tn = tmp * seq[i];
		}
		else
		{
			tn *= seq[i];
			tun *= seq[i];
		}
		if (tn < 1)
		{
			tn = 1;
		}
		if (tun > -1)
		{
			tun = -1;
		}
		if (tn > tmax)
		{
			tmax = tn;
		}
	}
	return tmax;
}

TEST(recursive, maxsubsequence)
{
	int seq[] =
	{ 2, 3, 4, -12, 2, 45, 6, -32, 3, 4, 5, 30 };
	int rtn = maxSubsequence(seq, sizeof seq / sizeof seq[0]);
	EXPECT_EQ(rtn, 63);

	int seq2[] =
	{ -1, -3, -4, -1, -10 };
	rtn = maxSubsequence(seq2, sizeof seq2 / sizeof seq2[0]);
	EXPECT_EQ(rtn, 0);
}

TEST(recursive, maxmultiple)
{
	double seq[] =
	{ 3.4, 2.3, 0.001, 23, 0.00001, 200, 11.1 };
	double rtn = maxMultipleSubseq(seq, sizeof seq / sizeof seq[0]);
	EXPECT_EQ(rtn, 2220);

	double seq2[] =
	{ -1.3, -2.4, 1.33, -30, 1, -0.4 };
	rtn = maxMultipleSubseq(seq2, sizeof seq2 / sizeof seq2[0]);
	EXPECT_DOUBLE_EQ(rtn, 124.488);

	double seq3[] =
	{ -1.3, 2.5, 9.1, 0, -35, 90, -20, 0 };
	rtn = maxMultipleSubseq(seq3, sizeof seq3 / sizeof seq3[0]);
	EXPECT_EQ(rtn, 63000);
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
