#include <iostream>

using namespace std;

double n;
int k;
int main(void)
{
    scanf("%lf%d", &n, &k);
    switch (k)
    {
    case 1:
        printf("%.1lf\n", n);
        break;
    case 2:
        printf("%.2lf\n", n);
        break;
    case 3:
        printf("%.3lf\n", n);
        break;
    case 4:
        printf("%.4lf\n", n);
        break;
    case 5:
        printf("%.5lf\n", n);
    }
}
