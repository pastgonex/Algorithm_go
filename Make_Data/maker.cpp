#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>

using namespace std;

// const int MOD = 1e9 + 7;
const int GROUP_NUM = 20;
const int N = 200;

double double_Rand(double min, double max) {
    return min + rand() / (double) (RAND_MAX / (max - min));
}

int int_Rand(int min, int max) {
    return int(min + rand() % (max - min));
}

void make_data() //!造数据的函数
{
    int n = int_Rand(1, 101);
    while (n--) {
        int a = int_Rand(65, 123);
        printf("%c", a);
    }

    // // int t = int_Rand(1, 12);         //!生成t组，t属于[1,11) 的int型
    // int n = int_Rand(1, 1e4 + 1);
    // int m = int_Rand(1, 1e4 + 1);
    // printf("%d %d\n", n, m);
    // int n = int_Rand(1, 101);
    // int k = int_Rand(1, n);
    // printf("%d %d\n", n, k);
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <=int_Rand(1, 11); j++) printf("%c", int_Rand(97, 123));
    //     puts("");
    // }
    // printf("%d %d\n", n, m);
    // for(int i = 0; i < n; i++) printf("%d ", int_Rand(-1e3, 1e3));
    // puts("");
    // while(m--)
    // {
    //     int l = int_Rand(1, n + 1);
    //     int r = int_Rand(1, n + 1);
    //     while(l > r) l = int_Rand(1, n + 1);
    //     printf("%d %d", l, r);
    //     puts("");
    // }
}

int main() {
    srand((unsigned) time(NULL));
    for (int i = 1; i <= 20; i++) { //!生成 GROUP_NUM个in
        char s[10000];
        sprintf(s, "%d.in", i);  //!生成对应的in
        freopen(s, "w", stdout); //!把输出的东西重定向到in
        make_data();             //!造数据的函数
    }
    return 0;
}
