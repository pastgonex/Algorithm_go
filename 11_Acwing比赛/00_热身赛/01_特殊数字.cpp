#include <iostream>

using namespace std;

int n;

// 转化成 string 好处理一些
bool judge(int n)
{
    string s = to_string(n);
    int res = 0;
    for (auto c : s) {
        res += c - '0';
    }
    return res % 4 == 0;
}

int main()
{
    cin >> n;
    while (!judge(n)) {
        n++;
    }
    cout << n << endl;
    return 0;
}