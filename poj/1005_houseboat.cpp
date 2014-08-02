#include <iostream>
#include <cmath>

using namespace std;
const double PI = 3.1415926;

int main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        cout << "Property " << i + 1 << ": This property will begin eroding in year " << ceil(PI*(x*x + y*y)/100.0) << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}
