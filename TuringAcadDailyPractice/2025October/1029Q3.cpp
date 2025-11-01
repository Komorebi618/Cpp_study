#include <iostream>
using namespace std;

int main() {
    int n, guess = 50, min = 1, max = 100, count = 1;
    cout << "要猜的数字是：";
    cin >> n;

    while (true) {
        cout << guess << endl;
        if (guess == n) {
            cout << count << endl;
            return 0;
        }
        else if (guess > n) {
            max = guess - 1; // 猜大了，范围最大值变小
        }
        else {
            min = guess + 1; // 猜小了，范围最小值变大
        }
        guess = (min + max) / 2;
        count++;
    }
}
