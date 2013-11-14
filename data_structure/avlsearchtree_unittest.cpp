#include <iostream>
#include <gtest/gtest.h>
#include "avlsearchtree.h"

int testKey[] = {23,3,4,65,32,87,9,6,21,10,39,42};
double testValue[] = {            
    1324.12,2314.12,4325.32,64432.123,
    34.12,23.12,4545.768,79.32,
    675.12,234536.467,765.453,632.123,
};
TEST(avlsearchtree, normal)
{
    AVLSearchTree<int, double> bst;
    for (int i = 0; i < 12; i++) {
        bst.insert(testKey[i], testValue[i]);
    }
    std::cout << bst << std::endl;

    EXPECT_EQ(bst.size(), 12);
    EXPECT_EQ(bst.height(), 4);

    // remove some node
    double value;
    bst.remove(10, value);
    EXPECT_EQ(bst.height(), 4);
    EXPECT_EQ(bst.size(), 11);
    EXPECT_EQ(value, 234536.467);

    bst.remove(65, value);
    EXPECT_EQ(value, 64432.123);

    bst.remove(6, value);
    EXPECT_EQ(value, 79.32);
    int rst = bst.find(6, value);
    EXPECT_EQ(rst, URANUS_EMPTY_TREE);

    bst.find(87, value);
    EXPECT_EQ(value, 23.12);
    rst = bst.find(65, value);
    EXPECT_EQ(rst, URANUS_EMPTY_TREE);

}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
