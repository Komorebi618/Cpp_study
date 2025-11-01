#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 1, n;
    cout << "时间将流逝几个月？" << endl;
    cin >> n;
    for (int i = 2; i < n; i++) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    cout << "经过" << n << "个月后，你有了" << b << "对兔子" << endl;

    return 0;
}