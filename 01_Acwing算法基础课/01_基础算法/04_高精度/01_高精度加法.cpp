//
// Created by Genes on 2020/11/28.
//
// 高精度加法
// #include <iostream>
// #include <vector>

// #define ios                               \
//     ios::sync_with_stdio(false); \
//     cin.tie(nullptr);                     \
//     cout.tie(nullptr)

// using namespace std;

// string a, b;
// vector<int> A, B;

// vector<int> add(vector<int> &A, vector<int> &B) { //加上引用是为了提高效率, 就不需要拷贝整个数组了
//     vector<int> C;
//     int t = 0;
//     for (int i = 0; i < A.size() || i < B.size(); i++) { // 模拟一个加法的过程
//         if (i < A.size()) {
//             t += A[i];
//         }
//         if (i < B.size()) {
//             t += B[i];
//         }
//         // 此时的t是A[i]+B[i]+ (前一位A[i-1]和B[i-1]是否有进位,有就+1,无则0)
//         C.push_back(t % 10); //最终答案的当前位为 t的个位
//         t /= 10; //用于下一个位(A[i+1],B[i+1]) 是否有进位--> 每次循环, 都用t+A+B
//     }
//     if (t) { //如果最高位有进位, 那么添上1
//         C.push_back(1);
//     }
//     return C;
// }

// int main() {
//     ios;
//     cin >> a >> b;
//     for (int i = a.size() - 1; i >= 0; i--) {
//         A.push_back(a[i] - '0');
//     }
//     for (int i = b.size() - 1; i >= 0; i--) {
//         B.push_back(b[i] - '0'); //减去一个偏移量 => b[i]这个字符表示的数字
//     }
//     auto C = add(A, B);

//     for (int i = C.size() - 1; i >= 0; i--) { //因为是倒着存的, 因此要倒着输出
//         cout << C[i];
//     }
//     cout << endl;
//     return 0;
// }
#include <iostream>
#include <vector>

using namespace std;

const int base = 1e9;

vector<int> add(vector<int>& A, vector<int>& B)
{
    if (A.size() < B.size()) {
        return add(B, A);
    }

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) {
            t += B[i];
        }
        C.push_back(t % base);
        t /= base;
    }
    if (t) {
        C.push_back(t);
    }

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;

    for (int i = a.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--) {
        s += (a[i] - '0') * t;
        j++, t *= 10;
        if (j == 9 || i == 0) {
            A.push_back(s);
            s = j = 0;
            t = 1;
        }
    }

    for (int i = b.size() - 1, s = 0, j = 0, t = 1; i >= 0; i--) {
        s += (b[i] - '0') * t;
        j++, t *= 10;
        if (j == 9 || i == 0) {
            B.push_back(s);
            s = j = 0;
            t = 1;
        }
    }

    auto C = add(A, B);

    cout << C.back();
    for (int i = C.size() - 2; i >= 0; i--) {
        printf("%09d", C[i]);
    }
    cout << endl;
    return 0;
}