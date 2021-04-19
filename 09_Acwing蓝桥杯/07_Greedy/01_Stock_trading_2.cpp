//
// Created by Genes on 2020/10/15.
//
// 股票买卖2
// 贪心
/*
    贪心:
        1. 最优
        2. 短视
    贪心一般是猜一下做法, 然后证明其正确性
    相邻两天:
        后>前--> 就买

        任何一个跨度>1的交易, 一定可以拆分成若干个==1天的交易
        那么对于这个问题的任何一次买卖的交易, 全部可以拆分成跨度为1的交易, 然后拼起来

        只要我后一天比前一天大, 那么就买--> 一定是最优解(只考虑当前--> 短视)

 */
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int profit;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n - 1; i++) {
        if (a[i] < a[i + 1]) {
            profit += a[i + 1] - a[i];
        }
    }
    cout << profit << endl;
    return 0;
}
