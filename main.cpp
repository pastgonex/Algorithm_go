#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 2e5 + 10;

#define value first
#define before_sort second

PII a[N];
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].value;
        a[i].before_sort = i;
    }
    sort(a, a + n);
    int res = 1;
    for (int i = 0, last = n + 1, dir = -1; i < n;) {
        int j = i + 1;
        while (j < n && a[i].value == a[j].value) {
            j++;
        }
        int minx = a[i].before_sort, maxx = a[j - 1].before_sort;
        if (dir == -1) {
            if (last > maxx) {
                last = minx;
            } else {
                last = maxx, dir = 1;
            }
        } else {
            if (last < minx) {
                last = maxx;
            } else {
                res++;
                last = minx;
                dir = -1;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
