/*
 * Project: 03_Mathematics_thinking
 * File Created:Wednesday, January 6th 2021, 10:46:18 pm
 * Author: Bug-Free
 * Problem:03_求出n的阶乘最右边非0位上的数字是几
 */
#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    int ans = 1, a = 0, b = 0;
    for (int i = 2; i <= n; i++) {
        int t = i;
        while (t % 2 == 0) {  //求出当前数字i上, 有多少个2的幂次
            t /= 2;
            a++;
        }
        while (t % 5 == 0) {  //求出当前数字i上, 有多少个5的幂次
            t /= 5;
            b++;
        }
        // 公式 (a1*a2*...*an)%10 = (a1%10 * a2%10 *...* an%10)%10
        ans = ans * t % 10;
    }
    // a>=b, 因此最后可以产生 b个0(可以不用管), 最后剩下a-b个2需乘入答案
    for (int i = 0; i < a - b; i++) {
        ans = ans * 2 % 10;
    }
    cout << ans << endl;
    return 0;
}
