#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "所打印菱形的边长为：";
    cin >> n;

    /*
        以n=5为例：（空格用"_"表示）
        ____*
        ___***
        __*****
        _*******
        *********
        _*******
        __*****
        ___***
        ____*
    */
    // 最长一行有 2*n - 1 个"*"字符
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        // i表示当前是第几行
        int spacesNum, starsNum;

        if (i <= n) {
            // 上半部分
            spacesNum = n - i; // 上半部分空格数：4,3,2,1,0，即 n-i
            starsNum = 2 * i - 1; // 上半部分星号数：1,3,5,7,9，即 2*i-1
        }
        else {
            // 下半部分
            spacesNum = i - n; // 下半部分空格数：1,2,3,4，即 i-n
            starsNum = 2 * (2 * n - i) - 1; // 下半部分星号数：7,5,3,1，即 2*(2*n-i)-1
        }

        // 打印空格
        for (int j = 0; j < spacesNum; j++) {
            cout << " ";
        }
        // 打印星号
        for (int j = 0; j < starsNum; j++) {
            cout << "*";
        }
        cout << endl; // 换行，使输出美观
    }
    return 0;
}