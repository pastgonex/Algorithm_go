#include <algorithm>
#include <iostream>

using namespace std;

const int N = 5;

int a[N];

int main()
{
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    sort(a, a + 4);
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int j = i + 1;
        while (a[i] == a[j]) {
            ans++;
            j++;
        }
        i = j - 1;
    }
    cout << ans << endl;
    return 0;
}