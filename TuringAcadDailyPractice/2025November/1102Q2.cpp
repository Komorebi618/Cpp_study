#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int maxStart = 0;    // 最长单词的起始位置
    int maxLen = 0;      // 最长单词的长度
    int start = 0;       // 当前单词的起始位置
    int len = 0;         // 当前单词的长度
    bool inWord = false; // 是否在单词中

    for (int i = 0; i <= str.length(); i++)
    {
        // 判断是否是字母
        if (i < str.length() && ((str[i] >= 'a' && str[i] <= 'z') || \
            (str[i] >= 'A' && str[i] <= 'Z')))
        {
            if (!inWord)
            {
                // 开始一个新单词
                start = i;
                len = 1;
                inWord = true;
            }
            else
            {
                // 继续当前单词
                len++;
            }
        }
        else
        {
            // 遇到非字母字符，单词结束
            if (inWord)
            {
                // 更新最长单词
                if (len > maxLen)
                {
                    maxLen = len;
                    maxStart = start;
                }
                inWord = false;
            }
        }
    }

    cout << maxStart << " " << maxLen << endl;

    return 0;
}