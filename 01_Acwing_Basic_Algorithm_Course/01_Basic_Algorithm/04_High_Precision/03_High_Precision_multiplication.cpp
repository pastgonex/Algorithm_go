//
// Created by Genes on 2020/11/29.
//
// 高精度乘法
#include <iostream>
#include <vector>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

vector<int> mul(vector<int> &A, int b) {
    vector<int> C;
    int t = 0; //第0位的进位是0(没有
    for (int i = 0; i < A.size() || t; i++) { //只有A还有或者t不为0, 就做, 最后t是不会剩下的
        if (i < A.size()) {
            t += A[i] * b;
        }
        C.push_back(t % 10);
        t /= 10;
    }
//    if(t){
//        C.push_back(t);
//    }
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

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i--) {
        cout << C[i];
    }
    cout << endl;
    return 0;
}