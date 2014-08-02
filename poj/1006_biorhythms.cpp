#include <iostream>

using namespace std;

const int MAX = 23 * 28 * 33;

int main(int argc, const char *argv[])
{
    int p = 0, e = 0, i = 0, d = 0;
    int count = 1;
    while(1) {
        cin >> p >> e >> i >> d;
        if (p == -1 && e == -1 && i == -1&& d == -1) {
            break;
        }
        int rst = 28*33*14*7*p + 23*33*11*17*e + 23*28*23*13*i - d;
        rst %= MAX;
        if (rst <= 0) {
            rst += MAX;
        }
        cout << "Case " << count << ": the next triple peak occurs in " << rst << " days." << endl;
        count ++;
    }
    return 0;
}
