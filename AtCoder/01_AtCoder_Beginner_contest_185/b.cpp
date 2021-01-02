// #include <algorithm>
// #include <iostream>

// using namespace std;

// int ri() {
//     int n;
//     cin >> n;
//     return n;
// }

// int main() {
//     int n = ri();
//     int m = ri();
//     int t = ri();
//     int last_time = 0;
//     int cur = n;
//     bool res = true;
//     for (int i = 0; i <= m; i++) {
//         int a = i < m ? ri() : t;
//         int b = i < m ? ri() : t;
//         cur -= a - last_time;
//         if (cur <= 0)
//             res = false;
//         cur = min(n, cur + b - a);
//         last_time = b;
//     }
//     puts(res ? "Yes" : "No");
//     return 0;
// }

#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;
#define a first
#define b second

PII alls[N];
int n, m, t;

int main() {
    cin >> n >> m >> t;
    int temp = n;
    for (int i = 0, last = 0; i < m; i++) {
        cin >> alls[i].a >> alls[i].b;
        n -= alls[i].a - last;
        if (n <= 0) {
            cout << "No" << endl;
            return 0;
        }
        n += alls[i].b - alls[i].a;
        n > temp ? n = temp : n;
        last = alls[i].b;
    }
    n -= t - alls[m - 1].b;
    if (n <= 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    // cout << n << endl;
    return 0;
}
