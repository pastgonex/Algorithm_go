/*
 * Project: 09_Disjoint_Set
 * File Created:Friday, January 8th 2021, 2:42:03 pm
 * Author: Bug-Free
 * Problem: AcWing 836. 合并集合
 */
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int fa[N];

int n, m;

int Get(int x) {
    if (x == fa[x]) {
        return x;
    }
    return fa[x] = Get(fa[x]);
}

void merge(int x, int y) {
    fa[Get(x)] = Get(y);
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {  //初始化
        fa[i] = i;
    }
    while (m--) {
        char op[2];
        int a, b;
        cin >> op >> a >> b;
        if (op[0] == 'M') {
            // if (Get(a) != Get(b)) {
            //     merge(a, b);
            // }
            merge(a, b);
        } else {
            cout << (Get(a) == Get(b) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
