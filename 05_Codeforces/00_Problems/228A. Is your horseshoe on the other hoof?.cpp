#include <algorithm>
#include <iostream>

using namespace std;

const int N = 5e1 + 5;

int n, m;
int a[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a, a + m);
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= m - n; i++) {
        int j = i + n - 1;
        ans = min(a[j] - a[i], ans);
    }
    cout << ans << endl;
    return 0;
}
