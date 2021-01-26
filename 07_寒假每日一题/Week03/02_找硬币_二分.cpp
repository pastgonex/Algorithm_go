#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N];

bool find(int x, int y)
{
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= y) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (a[l] != y) {
        return false;
    }
    if (x != y) {
        return true;
    }
    return a[l] == a[l + 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        int x = a[i], y = m - a[i];
        if (find(x, y)) {
            cout << x << " " << y << endl;
            return 0;
        }
    }
    puts("No Solution");
    return 0;
}
