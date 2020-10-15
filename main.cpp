#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int profit;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i + 1]) {
            profit += a[i + 1] - a[i];
        }
    }
    cout << profit << endl;
    return 0;
}