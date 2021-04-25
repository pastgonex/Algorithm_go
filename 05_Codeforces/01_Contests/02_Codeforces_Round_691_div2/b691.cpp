//
// Created by Genes on 2020/12/19.
//
#include<iostream>

using namespace std;

typedef long long ll;

int n;
ll ans = 1;

int main() {
    cin >> n;
    if (n % 2 == 1)
        ans = 2;
    int g1 = (n + 1) / 2, g2 = n / 2;
    ans = ans * (g1 + 1) * (g2 + 1);
    printf("%lld\n", ans);
}