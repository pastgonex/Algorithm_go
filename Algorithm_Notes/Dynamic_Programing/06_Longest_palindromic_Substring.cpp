//
// Created by Genes on 2020/9/8.
//
// 最长回文子串
//
// dp[i][j] 表示 s[i] 至 s[j]如果是回文子串则为1, 反之则为0
// 1. s[i]==s[j]  那么只需要 s[i+1], s[j-1]是回文子串, s[i]至s[j] 就是回文子串:
//  dp[i][j] = dp[i+1][j-1]
// 2. s[i]!=s[j]:
// dp[i][j] = 0    s[i]至s[j]不是回文子串
// 根据从边界出发的原理, 注意到边界都是长度为1或2的子串, 每次转移都对子串的长度-1, dp[i][j] = dp[i+1][j-1]
// 不妨考虑按子串的长度和子串的初始位置进行枚举
// 第一遍先枚举长度为3的子串的dp值, 然后第二遍枚举长度为4的子串的dp值
#include<iostream>
#include<string>

using namespace std;

const int N = 1e4 + 10;

bool dp[N][N];
string s;

int main() {
    ios::sync_with_stdio(false);
    getline(cin, s); // 要读入空格
    int len = s.length(), ans = 1;
    for (int i = 0; i < len; i++) {
        dp[i][i] = true;
        if (i < len - 1) {
            dp[i][i + 1] = true;
            ans = 2; //初始化时注意当前最长回文子串的长度
        }
    }
    //状态转移方程
    for (int l = 3; l <= len; l++) {
        for (int i = 0; i + l - 1 < len; i++) {// 子串的起始端点
            int j = i + l - 1; //右端点
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                ans = l; //更新最长回文子串的长度
            }
        }
    }
    cout << ans << endl;
    return 0;
}

