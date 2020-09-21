//
// Created by Genes on 2020/9/15.
//
// 特别数之和

#include<iostream>

using namespace std;

int n;
int res;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp = i;
        while (temp) {
            int t = temp % 10;
            if (t == 0 || t == 1 || t == 2 || t == 9) {
                res += i;
                break;
            }
            temp /= 10;
        }
    }
    cout << res << endl;
    return 0;
}
