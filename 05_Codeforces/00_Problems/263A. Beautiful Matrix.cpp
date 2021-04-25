// 思路： 最短Hamilton路径
#include <cmath>
#include <iostream>

using namespace std;

const int N = 6;

int g[N][N];

int main()
{
    int x, y;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> g[i][j];
            if (g[i][j] == 1) {
                x = i, y = j;
            }
        }
    }

    cout << abs(3 - x) + abs(3 - y) << endl;

    return 0;
}