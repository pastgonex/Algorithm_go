/*
 * Project: 0x15_String
 * File Created:Tuesday, January 5th 2021, 2:26:49 pm
 * Author: Bug-Free
 * Problem:AcWing 141. 周期
 */
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
char str[N];
int Next[N];

void get_next() {
    Next[1] = 0;  // 可以不写, 因为定义了一个全局的Next数组
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && str[i] != str[j + 1]) {  // 直到退无可退
            j = Next[j];
        }
        if (str[i] == str[j + 1]) {
            j++;
        }
        Next[i] = j;
    }
}

int main() {
    int T = 1;
    while (cin >> n, n) {
        cin >> (str + 1);
        get_next();
        cout << "Test case #" << T++ << endl;
        for (int i = 2; i <= n; i++) {
            int t = i - Next[i];
            //最大循环次数就是i/(i-next[i])
            // i-next[i]能整除i的条件是为了保证循环元每次重复的完整性
            if (Next[i] && i % t == 0) {  //特别要注意判断Next[i]是否为0
                cout << i << " " << i / t << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
