//
// Created by Genes on 2020/11/29.
//
// 高精度减法

#include <iostream>
#include <vector>

#define ios                               \
     ios::sync_with_stdio(false); \
     cin.tie(nullptr);                     \
     cout.tie(nullptr)

using namespace std;

bool cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) {
        return A.size() > B.size();
    }
    for (int i = A.size() - 1; i >= 0; i--) {
        if (A[i] != B[i]) {
            return A[i] > B[i];
        }
    }
    return true;// a.size()==b.size()
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) {
            t -= B[i];
        }
        //到目前为止算了 A[i]-B[i]-t;
        C.push_back((t + 10) % 10);// 解决了 t>=0, 和<0的问题
        if (t < 0) t = 1; //如果t<0, 说明它需要向前面借一位
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) { //去除前导零
        C.pop_back();//往后弹出, 直到C.size()==0 或者 C.back()!=0
    }
    return C;
}

int main() {
    ios;
    vector<int> A, B;
    string a, b;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0');
    }
    vector<int> C;
    if (cmp(A, B)) {
        C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
    } else {
        C = sub(B, A);
        cout << "-";
        for (int i = C.size() - 1; i >= 0; i--) {
            cout << C[i];
        }
    }
    cout << endl;
    return 0;
}
