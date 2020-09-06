//
// Created by Genes on 2020/9/3.
//
#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = n;
    while (n >= 3) {
        ans += n / 3;
        n = n / 3 + n % 3;
    }
    cout << ans << endl;
    return 0;
}
