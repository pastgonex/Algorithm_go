//
// Created by Genes on 2020/12/6.
//
#include <iostream>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], b[N];

int main() {
    ios;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int j = 0;
    // 看看其每一个元素另一个数组中是不是在都有各自的下标
    // 且下标要呈递增趋势，这就有了单调性 可以用双指针
    for (int i = 0; i < m; i++) {
        if (j < n && a[j] == b[i]) {
            j++;
        }
    }
    // xc哥写法
//    int i = 0, j = 0;
//    while (i < n && j < m)
//    {
//        if (a[i] == b[j]) i ++ ;
//        j ++ ;
//    }

    if (j == n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
