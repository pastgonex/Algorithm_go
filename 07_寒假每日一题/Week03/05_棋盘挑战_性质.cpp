/*
 * Project: Week03
 * File Created:Friday, January 22nd 2021, 4:22:20 pm
 * Author: Bug-Free
 * Problem:AcWing 1432. 棋盘挑战
 */
// 发现一个性质，每行只能放一个棋子，因此只需要枚举每一行即可
#include <iostream>

using namespace std;

const int N = 1e1 + 5;

int n;
bool col[N], dg[N * 2], udg[N * 2];  // 列， 正对角线， 反对角线
int path[N];

int ans;

void dfs(int x) {
    if (x > n) {
        ans++;
        if (ans <= 3) {  //输出前三个
            for (int i = 1; i <= n; i++) {
                if (i > 1) {
                    cout << " ";
                }
                cout << path[i];
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!col[i] && !dg[n + i - x] && !udg[i + x]) {
            col[i] = dg[n + i - x] = udg[i + x] = true;
            path[x] = i;
            dfs(x + 1);
            col[i] = dg[n + i - x] = udg[i + x] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}
