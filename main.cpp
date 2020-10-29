#include<iostream>

#include<algorithm>

using namespace std;

bool cmp(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    puts("");
    return 0;
}