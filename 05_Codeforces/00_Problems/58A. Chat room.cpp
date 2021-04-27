// 贪心， O(N)
#include <iostream>

using namespace std;

string str;
string base = "hello";

int main()
{
    cin >> str;
    int k = 0;
    bool flag = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == base[k]) {
            k++;
        }
        if (k == base.size()) {
            flag = true;
            break;
        }
    }
    if (flag) {
        puts("YES");
    }
    else {
        puts("NO");
    }
    return 0;
}