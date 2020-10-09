//
// Created by Genes on 2020/10/8.
//
// 冒泡排序
// 每次比较, 将最大的沉到后面

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) { //给j+1留一个位置, 不要越界, 每一轮将最大的沉到后面
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    puts("");
    return 0;
}
