//
// Created by Genes on 2020/12/6.
//
// 给定一个字符串a,
// 先观察是否有tryout, 如果有则改变顺序

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e2 + 10;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-6;

char str[N];

int main() {
    ios;
    int t;
    cin >> t;
    char tuple[10] = "trygub";
    while (t--) {
        int n;
        cin >> n >> str;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j == 6) {
                j = 0;
            }
            if (str[i] == tuple[j]) {
                j++;
            }
            if (j == 6) {
                swap(str[j - 1], str[j - 2]);
            }
        }
        cout << str << endl;
    }
    return 0;
}