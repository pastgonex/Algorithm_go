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

void make_data(int m) //!造数据的函数
{
    printf("%d\n", m);
}

int main() {
    srand((unsigned) time(NULL));
    for (int i = 1; i <= 15; i++) { //!生成 GROUP_NUM个in
        char s[10000];
        sprintf(s, "%d.in", i);  //!生成对应的in
        freopen(s, "w", stdout); //!把输出的东西重定向到in
        make_data(i);             //!造数据的函数
    }
    return 0;
}
