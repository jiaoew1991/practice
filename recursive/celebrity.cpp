#include "common/error_code.h"
#include "common/log.h"
#include <gtest/gtest.h>

/**
 * @brief 
 *
 * @param   matrix  if a know b then matrix[a][b] = 1 else matrix[a][b] = 0;
 * @param   n
 *
 * @returns   
 */
int celebrity(int** matrix, int n)
{
    int a = 0, b = 1;
    int next = 2;
    int candidate;
    while (next <= n) {
        if (matrix[a][b]) {
            a = next;
        } else {
            b = next;
        }
        next++;
    }
    if (a == n) {
        candidate = b;
    }
    else {
        candidate = a;
    }
    std::cout << candidate << std::endl;
    int wrong = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[candidate][i] && candidate != i) {
            wrong = 1;
            break;
        } 
        else if (matrix[i][candidate] == 0 && candidate != i) {
            wrong = 1;
            break;
        }
    }
    if (wrong) {
        return -1;
    }
    return candidate;
}

TEST(recursive, celebrity)
{
    int a[4][4] = {
        { 0, 1, 1, 1, },
        { 1, 0, 1, 1, },
        { 0, 0, 0, 0, },
        { 1, 0, 1, 0, },
    };
    int** pa = new int* [4];
    for (int i = 0; i < 4; i++) {
        pa[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            pa[i][j] = a[i][j];
        }
        std::cout << "i: " << i << std::endl;
    }
    int rst = celebrity(pa, 4);
    EXPECT_EQ(rst, 2);
}
int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
