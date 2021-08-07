//
// Created by Genes on 2020/11/29.
//
// 高精度除法
#include <iostream>
#include<vector>
#include<algorithm>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

vector<int> div(vector<int> &A, int b, int &r) {
    vector<int> C;
    r = 0; //余数
    for (int i = A.size() - 1; i >= 0; i--) { // 除法是从最高位开始算的
        r = r * 10 + A[i];// 余数*10+当前这一位
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end()); //倒过来是为了适配 加减乘--> 很多题目都不只一种运算
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    return C;
}

int main() {
    ios;
    string a;
    int b;
    cin >> a >> b;

    vector<int> A;//
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    int r;
    auto C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    
    cout << endl << r << endl;
    return 0;
}