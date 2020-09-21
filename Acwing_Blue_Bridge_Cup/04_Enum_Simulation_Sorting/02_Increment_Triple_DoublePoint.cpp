// 递增三元组
// 双指针做法

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

int a[N], b[N], c[N];
int n;
ll res;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
        int key = b[i];
        while (j < n && a[j] < key) j++;
        while (k < n && c[k] <= key) k++;
        res += (ll) j * (n - k);
    }
    cout << res << endl;
    return 0;
}