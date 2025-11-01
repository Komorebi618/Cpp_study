#include <iostream>
using namespace std;

int main() {
    int n, count = 0;
    cin >> n;
    int* arr = new int[n];
    // 因为数组的大小由变量n决定，所以这里使用new动态分配数组（动态内存分配，要记得delete释放空间）
    /* C++也推荐使用vector：
    #include <vector>  // 记得在文件开头包含这个头文件

        int n;
        cin >> n;
        std::vector<int> arr(n);
    */
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // 循环读取输入在一行的n个四位数
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % 10 - arr[i] / 1000 - arr[i] / 100 % 10 - arr[i] / 10 % 10 > 0) {
            // 如题目提示：分离出各位数字进行计算的方法
            // 个位=num%10,十位=(num/10)%10,百位=(num/100)%10,千位=num/1000
            // 由此我们也可总结得到一个规律：第k位数字 = (num/10^(k-1))%10
            // 即先用整数除法去掉后面的k-1位数字，再用取模运算得到个位数字
            count++;
        }
    }
    cout << count << endl;

    delete[] arr; // 一定要记得释放动态分配的内存
    return 0;
}
