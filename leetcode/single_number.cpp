#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
            twos = ones & A[i];
            ones ^= A[i];
            ones &= ~twos;
            //threes = ones & twos;
            //ones &= ~threes;
            //twos &= ~threes;
            cout << "one: " << ones << ", two: " << twos << ", three" << threes << endl;
        }
        return ones;
    }
};
int main(int argc, const char *argv[])
{
    Solution s;
    int arr[] = {17, 12, 5, -6, 12, 4, 17, -5, 2, -3, 2, 4, 5, 16, -3, -4, 15, 15, -4, -5, -6};

    int rst1 = s.singleNumber(arr, 21);
    cout << "rst is " << rst1 << endl;
    return 0;
}
