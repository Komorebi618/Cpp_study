#include <iostream>
using namespace std;

int main() {
    int x, y, z, n, m;
    // 每只公鸡x元，每只母鸡y元，每z只小鸡1元；现在有n元，买了m只鸡
    cin >> x >> y >> z >> n >> m; // 在一行中输入五个整数x,y,z,n,m
    int count = 0; // 记录方案数
    for (int male = 0; male <= m && male * x <= n; male++) {
        // 判断条件：当前购买鸡总数male不超过m且总价钱male*x不超过n
        for (int female = 0; (female + male) <= m && (female * y + male * x) <= n; female++)
            // 判断条件：当前购买鸡总数female+male不超过m且总价钱(female*y + male*x)不超过n
        {
            int little = m - male - female; // 计算小鸡数量
            if (little % z == 0 && (little / z + female * y + male * x) == n) {
                // 如果小鸡数为z的整数倍且总价钱等于n，则方案符合要求
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
