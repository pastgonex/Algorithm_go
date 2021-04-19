//
// Created by Genes on 2020/9/13.
//
// 连号区间数
// maxv - minv = b-a , 那么就说明这是一个连号区间

#include<iostream>
#include<climits>

using namespace std;

const int N = 1e4 + 10;

int a[N];
int n;
int res;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) { //枚举左端点
        int Max = INT_MIN, Min = INT_MAX;
        for (int j = i; j < n; j++) {
            Max = max(Max, a[j]);
            Min = min(Min, a[j]);
            if (Max - Min == j - i) res++;
        }
    }
    cout << res << endl;
    return 0;
}

