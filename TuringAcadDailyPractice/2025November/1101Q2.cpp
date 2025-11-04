#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char password[20];
    cout << "请输入密码：";
    cin >> password;

    bool lengthFlag, upperFlag, lowerFlag, digitFlag, specialFlag = false;
    if (strlen(password) >= 8 && strlen(password) <= 16)
    {
        lengthFlag = true;
    }
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"))
    {
        upperFlag = true;
    }
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz"))
    {
        lowerFlag = true;
    }
    if (strpbrk(password, "0123456789"))
    {
        digitFlag = true;
    }
    if (strpbrk(password, "~!@#%*"))
    {
        specialFlag = true;
    }
    if (lengthFlag && upperFlag && lowerFlag && digitFlag && specialFlag)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}