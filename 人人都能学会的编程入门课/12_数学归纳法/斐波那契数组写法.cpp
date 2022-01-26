#include <iostream>

using namespace std;

typedef long double ld;

const int N = 1e5 + 10;

int main(void)
{
    int n;
    scanf("%d", &n);
    ld *fic = new ld[N];
    fic[1] = fic[2] = 1;
    if (n <= 2)
        puts("1");
    else
    {
        for (int i = 3; i <= n; i++)
            fic[i] = fic[i - 1] + fic[i - 2];
        printf("%.0Lf\n", fic[n]);
    }
    delete[] fic; //动态数组记得释放
    return 0;
}
