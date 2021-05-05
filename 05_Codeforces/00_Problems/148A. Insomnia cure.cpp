// // O(N)
// #include <iostream>

// using namespace std;

// int k, l, m, n, d;

// int cnt;

// int main()
// {
//     cin >> k >> l >> m >> n >> d;
//     for (int i = 1; i <= d; i++) {
//         if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
//             cnt++;
//         }
//     }
//     cout << cnt << endl;
//     return 0;
// }

//O(1) 容斥原理
//1~n中能被 T 整除的数字数量为  n/T
// #include <iostream>
// #include <string>
// // #include<cstring>

// using namespace std;

// const int N = 1e1;

// int a[N], d;
// int res;
// bool st[N];

// int gcd(int a, int b)
// {
//     return b ? gcd(b, a % b) : a;
// }

// int lcm(int a, int b)
// {
//     return a * b / gcd(a, b);
// }

// void dfs(int u, int t, int start)
// {
//     for (int i = start; i < 4; i++) {
//         if (!st[i]) {
//             st[i] = true;
//             int temp = lcm(t, a[i]);
//             if (u & 1) {
//                 res += d / temp;
//             }
//             else {
//                 res -= d / temp;
//             }
//             dfs(u + 1, temp, i + 1);
//             st[i] = false;
//         }
//     }
// }

// int main()
// {
//     for (int i = 0; i < 4; i++) {
//         cin >> a[i];
//     }
//     cin >> d;

//     dfs(1, 1, 0);
//     cout << res << endl;
//     return 0;
// }

#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e1;

int a[N], d;
int res;
bool st[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

void dfs(int u, int t, int start)
{
    for (int i = start; i < 4; i++) {
        if (!st[i]) {
            st[i] = true;
            int temp = lcm(t, a[i]);
            if (u & 1) {
                res += d / temp;
            }
            else {
                res -= d / temp;
            }
            dfs(u + 1, temp, i + 1);
            st[i] = false;
        }
    }
}

int main()
{
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    cin >> d;
    dfs(1, 1, 0);
    cout << res << endl;
    return 0;
}