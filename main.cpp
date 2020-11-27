#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<deque>
#include<map>
#include<climits>
#include<cassert>
#include<cctype>

#define ios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define for_1(begin, end) for (int begin = 1; begin <= end; begin++)
#define for_0(begin, end) for (int being = 0; being < end; begin++)
#define for_(begin, val, end) for (int begin = val; begin < end; begin++)
#define for__(begin, val, end) for (int begin = val; begin <= end; begin++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
__unused const double PI = acos(-1.0);
const double eps = 1e-5; //保留3位小数, 就多开2

int n, f;
double a[N], b[N], sum[N];

bool check(double avg) {
    for_1(i, n) {
        b[i] = a[i] - avg;
    }
    for_1(i, n) {
        sum[i] = sum[i - 1] + b[i];
    }
    double ans = -1e10;
    double min_val = 1e10;
    for__(i, f, n) {
        min_val = min(min_val, sum[i - f]);
        ans = max(ans, sum[i] - min_val);
        if (ans >= 0) {
            return true;
        }
    }
    return false;
}

int main() {
    ios;
    cin >> n >> f;
    double l = -1e10, r = 1e10;
    for_1(i, n) {
        cin >> a[i];
        r = max(a[i], r);
    }
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << int(r * 1000) << endl;
    return 0;
}
