// 找出1000以内的幸运数字
#include <iostream>

using namespace std;

const int N = 5e1;

int luckys[N];
int n;

int init()
{
    int cnt = 0;
    for (int i = 4; i <= 1000; i++) {
        int t = i;
        bool flag = false;
        while (t) {
            int temp = t % 10;
            if (temp != 4 && temp != 7) {
                flag = true;
                break;
            }
            t /= 10;
        }
        if (!flag) {
            luckys[cnt++] = i;
        }
    }
    return cnt;
}

int main()
{
    int cnt = init();

    cin >> n;

    bool flag = false;
    for (int i = 0; i < cnt; i++) {
        if (n % luckys[i] == 0) {
            flag = true;
            break;
        }
    }

    puts(flag ? "YES" : "NO");

    return 0;
}
