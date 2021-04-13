// 预处理出所有的(c_a)^b
#include <iostream>

using namespace std;

const int N = 2e3 + 10, mod = 1e9 + 7;

int c[N][N];

// a，b的范围是2000， 一共有 2000^2 对不同的a和b -> 4e6
// 因此可以预处理出所有的c[a][b]

void init()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) {
                c[i][j] = 1;
            }
            else {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
    }
}

int main()
{
    int n;

    init();

    scanf("%d", &n);

    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);

        printf("%d\n", c[a][b]);
    }

    return 0;
}