/*
    思路:
        成绩第k名  == 降序排列的第k个  从1~n，a[k]
*/
#include <algorithm>
#include <atomic>
#include <iostream>

using namespace std;

const int N = 5e1 + 5;

int n, k;
int a[N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            continue;
        }
        if (a[i] >= a[k]) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}