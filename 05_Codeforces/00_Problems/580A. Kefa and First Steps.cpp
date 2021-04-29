// 朴素做法
// #include <algorithm>
// #include <climits>
// #include <iostream>

// using namespace std;

// const int N = 1e5 + 10;

// int n;
// int a[N];

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     int max_length = 1;
//     int res = 1;
//     for (int i = 1; i < n; i++) {
//         if (a[i] >= a[i - 1]) {
//             res++;
//         }
//         else {
//             max_length = max(max_length, res);
//             res = 1;
//         }
//     }
//     max_length = max(max_length, res);
//     cout << max_length << endl;
//     return 0;
// }

// 动态规划
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int dp[N], a[N];

// dp[i] 表示以第 i 个数字结尾的最长连续非降子序列的最大长度

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        cin >> a[i];
    }

    int ans = 1;
    for (int i = 1; i <= n - 1; i++) {
        dp[i + 1] = a[i] <= a[i + 1] ? dp[i] + 1 : 1;
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}