#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

const int N = 1e2 + 10;

int n, m;
int t;
int g[N][N], f[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
                f[j] = max(f[j], f[j - 1]) + g[i][j];
            }
        }
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + g[i][j];
//            }
//        }
        cout << f[m] << endl;
        memset(f, 0, sizeof f);
    }
    return 0;
}