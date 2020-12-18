#include<iostream>

using namespace std;
const int N = 1e5 + 10;
pair<string, int> a[N];
int n, m;

int calc(int bit, int now) {// 代表现在运算的是二进制的第几位， now有两种情况，需要运算过后返回
    for (int i = 0; i < n; i++) {
        int x = a[i].second >> bit & 1;// 首先取出第i次运算中的第几位进行二进制运算
        if (a[i].first == "OR") {
            now |= x;
        } else if (a[i].first == "XOR") {
            now ^= x;
        } else {
            now &= x;
        }
    }
    return now;// 现在返回的就是运算过后的二进制位
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    int ans = 0, v = 0;
    for (int i = 29; i >= 0; i--) {// m最多有29个二进制位，直接从高位到低位枚举每一位
        int r1 = calc(i, 0);// 查看填0之后是否变化
        int r2 = calc(i, 1);// 查看填1之后是否变化， 如果没有变化，加上该位后又小于m，就可以填1
        // 这里仅有四种情况 分别为0 0， 0 1， 1 0， 1 1
        // 仅有0 1 是满足可以填一的一个条件的，其他情况运算过后这一位都相反了，填0，后面运算还可能填1
        if (v + (1 << i) <= m && r2 > r1) {
            v += (1 << i), ans += r2 << i;// 满足填1的条件，直接填1
        } else {
            ans += r1 << i;// 不能填1，直接填0
        }
    }
    cout << ans << endl;// 最后的答案
    return 0;
}