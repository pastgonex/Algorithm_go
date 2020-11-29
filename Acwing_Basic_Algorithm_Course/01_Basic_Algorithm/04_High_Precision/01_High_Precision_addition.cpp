//
// Created by Genes on 2020/11/28.
//
// 高精度加法

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-6;

string a, b;
vector<int> A, B;

vector<int> add(vector<int> &A, vector<int> &B) { //加上引用是为了提高效率, 就不需要拷贝整个数组了
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++) { // 模拟一个加法的过程
        if (i < A.size()) {
            t += A[i];
        }
        if (i < B.size()) {
            t += B[i];
        }
        // 此时的t是A[i]+B[i]+ (前一位A[i-1]和B[i-1]是否有进位,有就+1,无则0)
        C.push_back(t % 10); //最终答案的当前位为 t的个位
        t /= 10; //用于下一个位(A[i+1],B[i+1]) 是否有进位--> 每次循环, 都用t+A+B
    }
    if (t) { //如果最高位有进位, 那么添上1
        C.push_back(1);
    }
    return C;
}

int main() {
    ios;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--) {
        B.push_back(b[i] - '0'); //减去一个偏移量 => b[i]这个字符表示的数字
    }
    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--) { //因为是倒着存的, 因此要倒着输出
        cout << C[i];
    }
    cout << endl;
    return 0;
}


