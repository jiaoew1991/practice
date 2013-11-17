#include "common/error_code.h"
#include "common/log.h"
#include <gtest/gtest.h>
#include <vector>

int polynominalEvaluation(std::vector<int>& paramList, int x)
{
    int rst = 0;
    for (size_t i = 0; i < paramList.size(); i++) {
        rst *= x;
        rst += paramList[i];
    }
    return rst;
}

TEST(recursive, polynomial)
{
    std::vector<int> paramList;
    paramList.push_back(2);
    paramList.push_back(3);
    paramList.push_back(1);
    int rst = polynominalEvaluation(paramList, 1);
    EXPECT_EQ(rst, 6);
    rst = polynominalEvaluation(paramList, 3);
    EXPECT_EQ(rst, 28);
}
int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
