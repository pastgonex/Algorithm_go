#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n;
int a[N];
int st[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << st[i];
    }
    puts("");
    return 0;
}