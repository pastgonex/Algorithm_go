/*
 * File: 01_木棒_Sticks.cpp
 * Project: 0x23_剪枝
 * File Created: Wednesday, 11th February 2021 2:17:12 am
 * Author: Bug-Free
 * Problem: AcWing 167. 木棒
 */
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 70;

int n;
int sum, length;
int sticks[N];
bool st[N];

bool cmp(int a, int b)
{
    return a > b;
}

bool dfs(int u, int cur, int start)
{
    if (u * length == sum) {
        return true;
    }

    if (cur == length) {
        return dfs(u + 1, 0, 0);
    }

    for (int i = start; i < n; i++) {
        if (st[i]) {
            continue;
        }
        int l = sticks[i];
        if (cur + l <= length) {
            st[i] = true;
            if (dfs(u, cur + l, i + 1)) {
                return true;
            }
            st[i] = false;

            // 剪枝3 如果是第一根木棍失败， 则一定失败
            if (!cur) {
                return false;
            }

            //剪枝4 如果是最后一根木棒失败， 则一定失败
            if (cur + l == length) {
                return false;
            }

            // 剪枝2 如果失败了， 则跳过相同的木棒
            int j = i;
            while (j < n && sticks[j] == l) {
                j++;
            }
            i = j - 1;
        }
    }
    return false;
}

int main()
{
    while (cin >> n, n) {
        sum = 0, length = 0;
        memset(st, false, sizeof st);

        for (int i = 0; i < n; i++) {
            cin >> sticks[i];
            if (sticks[i] > 50) {
                continue;
            }
            sum += sticks[i];
            length = max(length, sticks[i]);
        }

        // 剪枝: 优化搜索顺序
        // sort(sticks,sticks+n);
        // reverse(sticks,sticks+n);
        sort(sticks, sticks + n, cmp);

        for (int i = 0; i < n; i++) {
            if (sticks[i] > 50) {
                st[i] = true;
            }
        }

        while (true) {
            if (sum % length == 0 && dfs(0, 0, 0)) {
                cout << length << endl;
                break;
            }
            length++;
        }
    }

    return 0;
}