#include<iostream>

using namespace std;

const int N = 6e4;

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    int x[N] = {0};
    for (int i = 0; i < n; i++) cin >> x[i];
    int ltr = 0, rtl = 0;
    //  第一个元素是 感冒的蚂蚁
    for (int i = 1; i < n; i++) {
        if (abs(x[i]) > abs(x[0]) && x[i] < 0) rtl++;
        if (abs(x[i]) < abs(x[0]) && x[i] > 0) ltr++;
    }
    if (x[0] > 0 && !rtl || x[0] < 0 && !ltr) puts("1");
    else cout << rtl + ltr + 1 << endl;
    return 0;
}
