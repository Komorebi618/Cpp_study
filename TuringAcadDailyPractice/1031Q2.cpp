#include <iostream>
#include <vector>
using namespace std;

const int arr[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
// 用于取模运算，获取后几位数字，因为样例在10^7以内，所以取模10^7即可

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> bookCodes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bookCodes[i];
    }
    vector<vector<int>> require(q, vector<int>(2));
    // 二维数组，存储每个读者所需图书末位编码的位数和编码
    for (int i = 0; i < q; i++)
    {
        cin >> require[i][0] >> require[i][1];
    }

    for (int i = 0; i < q; i++)
    {
        // i是读者所需数组的下标
        int count = 0; // 记录i号读者找到所需书的数量
        for (int j = 0; j < n; j++)
        {
            // j是图书编码数组的下标
            if (bookCodes[j] >= require[i][1])
            {
                // 判断数字编码是否大于等于读者所需的编码（实际应该比较位数，但是效果相同）
                if (bookCodes[j] % (arr[require[i][0] - 1]) == require[i][1])
                {
                    // 提取出的后几位数字与读者所需编码进行比较
                    // 提取图书编码后几位数字的方法就是对10的对应次方取模，即arr数组中对应的值
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    /* 更优化的写法：
    const int digit[] = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    // 第一位存放0，方便后续取模运算

    for (int i = 1; i <= q; ++i) {
        int x, y; // x表示读者所需图书编码的位数，y表示读者所需图书编码
        cin >> x >> y; // x,y 直接读取即可，不需要用二维数组储存
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            int var1 = a[j] % digit[x]; // a 是存放书籍编码的数组
            if (var1 == y)
                ++cnt; // 这里使用 ++cnt 是因为前缀++ 比较高效，更适合这种只自增不用其返回值的场景
        }
        cout << cnt << endl;
    }

    */

    return 0;
}