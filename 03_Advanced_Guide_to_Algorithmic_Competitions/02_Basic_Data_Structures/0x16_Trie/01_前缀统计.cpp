/*
 * Project: 0x16_Trie
 * File Created:Friday, January 8th 2021, 4:05:18 am
 * Author: Bug-Free
 * Problem:AcWing 142. 前缀统计
 */
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, m;
char str[N];
int idx;
int son[N][26], cnt[N];

void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char str[]) {
    int p = 0;
    int res = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (son[p][u]) {
            p = son[p][u];
            res += cnt[p];
        } else {
            return res;
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    while (n--) {
        cin >> str;
        insert(str);
    }
    while (m--) {
        cin >> str;
        cout << query(str) << endl;
    }
    return 0;
}
