#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class ResultPairVector
{
public:
    ResultPairVector(vector<int> &a, vector<int> &b, int column) : inputValue(a), inputNumber(b) {
        mColumn = column;
    };
    ~ResultPairVector();
    void execute() {

    }
    void printResult() {
        printf("%d\n", mColumn);
        for (size_t i = 0; i < mValues.size(); i++) {
            printf("%d %d\n", mValues[i], mNumbers[i]);
        }
        printf("0 0\n");
    }
private:
    int pixelResult(int index, int offset) {
    }
private:
    vector<int>& inputValue;
    vector<int>& inputNumber;

    vector<int> mValues;
    vector<int> mNumbers;
    int mColumn;
};

int main(int argc, const char *argv[])
{
    int column = 0;
    scanf("%d", &column);
    vector<int> vValues;
    vector<int> vNumbers;
    while(column) {
        int value = -1, number = -1;
        while (value && number) {
            scanf("%d %d", &value, &number);
            vValues.push_back(value);
            vNumbers.push_back(number);
        }
        ResultPairVector r(vValues, vNumbers, column);
        r.execute();
        r.printResult();

        scanf("%d", &column);
    }
    printf("0");
    return 0;
}
