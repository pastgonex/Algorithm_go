/*
    思路：
        排序
        t1， t2， t3, ... , tn
        t1*(n-1) +  t2*(n-2) + ... t(n-1)*(1)
*/

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

typedef long long ll;

int n;
int a[N];
ll ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n - 1; i++) {
        ans += a[i] * (n - i);
    }

    cout << ans << endl;

    return 0;
}