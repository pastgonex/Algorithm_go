//思路： 贪心： 排序， 从小到大排序
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    return 0;
}
