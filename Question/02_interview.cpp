#include<iostream>

using namespace std;

int x, y;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        x |= t;
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        y |= t;
    }
    cout << x + y << endl;
    return 0;
}

