/*
 * Project: 0x14_Hash
 * File Created:Monday, January 18th 2021, 10:21:24 am
 * Author: Bug-Free
 * Problem:AcWing 137. 雪花雪花雪花
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

const int N = 1e5 + 10, P = 1e5 + 3;

int n, a[6], b[6];

struct S {
    int s[6];
};

vector<S> snow[N];

int H() {  //设计Hash函数
    int s = 0, k = 1;
    for (int i = 0; i < 6; i++) {
        (s += a[i]) %= P;      //和
        k = (ll)k * a[i] % P;  //积
    }
    return (s + k) % P;  // 和与积相加
}

bool judge() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            bool v = 1;
            for (int k = 0; k < 6; k++) {
                if (a[(i + k) % 6] != b[(j + k % 6)]) {
                    v = 0;
                    break;
                }
            }
            if (v) {
                return true;
            }
            v = 1;
            for (int k = 0; k < 6; k++) {
                if (a[(i + k) % 6] != b[(j - k + 6) % 6]) {
                    v = 0;
                    break;
                }
            }
            if (v) {
                return true;
            }
        }
    }
    return false;
}

bool insert() {
    int h = H();  //获取Hash值
    for (unsigned int i = 0; i < snow[h].size(); i++) {
        memcpy(b, snow[h][i].s, sizeof b);
        if (judge()) {
            return true;
        }
    }
    S s;
    memcpy(s.s, a, sizeof(s.s));
    snow[h].push_back(s);
    return 0;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> a[j];
        }
        if (insert()) {
            cout << "Twin snowflakes found." << endl;
            return 0;
        }
    }
    cout << "No two snowflakes are alike." << endl;
    return 0;
}
