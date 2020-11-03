#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>

typedef long long ll;

using namespace std;

typedef unsigned long long int UINT64;

UINT64 getRandom(const UINT64 &begin = 0, const UINT64 &end = 100) {
    return begin >= end ? 0 : begin + (UINT64) ((end - begin) * rand() / (double) RAND_MAX);
};

// const int MOD = 1e9 + 7;
const int GROUP_NUM = 20;
const int N = 200;

double double_Rand(double min, double max) {
    return min + rand() / (double) (RAND_MAX / (max - min));
}

ll int_Rand(ll min, ll max) {
    return ll(min + rand() % (max - min));
}

void make_data(int k) //!造数据的函数
{
    int a, b, h, w, n;
    if (k <= 5) {
        a = int_Rand(1, 1001);
        b = int_Rand(1, 1001);
        h = int_Rand(1, 1001);
        w = int_Rand(1, 1001);
        n = int_Rand(1, 1001);
        printf("%d %d %d %d %d\n", a, b, h, w, n);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", int_Rand(2, 1001));
        }
        puts("");
    }
    if (k > 5 && k <= 15) {
        a = int_Rand(1000, 50001);
        b = int_Rand(1000, 50001);
        h = int_Rand(1000, 50001);
        w = int_Rand(1000, 50001);
        n = int_Rand(1000, 50001);
        printf("%d %d %d %d %d\n", a, b, h, w, n);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", int_Rand(2, 1001));
        }
        puts("");
    }
    if (k > 15) {
        a = int_Rand(50001, 100001);
        b = int_Rand(50001, 100001);
        h = int_Rand(50001, 100001);
        w = int_Rand(50001, 100001);
        n = int_Rand(50001, 100001);
        printf("%d %d %d %d %d\n", a, b, h, w, n);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(" ");
            }
            printf("%d", int_Rand(2, 1001));
        }
        puts("");
    }
}

int main() {
    srand((unsigned) time(NULL));
    for (int i = 1; i <= 20; i++) { //!生成 GROUP_NUM个in
        char s[10000];
        sprintf(s, "%d.in", i);  //!生成对应的in
        freopen(s, "w", stdout); //!把输出的东西重定向到in
        make_data(i);             //!造数据的函数
    }
    return 0;
}
