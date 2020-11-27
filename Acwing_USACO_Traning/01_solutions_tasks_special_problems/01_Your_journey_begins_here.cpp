//
// Created by Genes on 2020/11/25.
//

#include<iostream>

#define mod 47

using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    int mul_1 = 1, mul_2 = 1;
    for (char i : a) {
        mul_1 *= (i - 'A' + 1) % mod;
    }
    for (char i : b) {
        mul_2 *= (i - 'A' + 1) % mod;
    }
    mul_1 % mod == mul_2 % mod ? cout << "GO" << endl : cout << "STAY" << endl;
    return 0;
}
