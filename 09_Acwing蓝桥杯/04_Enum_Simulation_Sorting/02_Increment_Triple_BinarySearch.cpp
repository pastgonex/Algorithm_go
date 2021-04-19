//
// Created by Genes on 2020/9/14.
//
// 递增三元组

//优化版本
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;


int n;
int a[N], b[N], c[N];
long long int ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(a, a + n);
    sort(c, c + n);
    for (int i = 0; i < n; i++) {
        int key = b[i];
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (a[mid] < key) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        if (a[l] >= b[i]) {
            l = -1;
        }
        int cnt_a = l;
        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (c[mid] > key) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (b[i] >= c[l]) {
            r = n; // n-cnt_c == 0
        }

        int cnt_c = r;
        ans += (ll) (cnt_a + 1) * (n - cnt_c);
    }
    cout << ans << endl;
    return 0;
}

//暴力版本
//#include<iostream>
//
//using namespace std;
//
//const int N = 1e5 + 10;
//
//int n;
//int a[N], b[N], c[N];
//int res;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> b[i];
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> c[i];
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            for (int k = 0; k < n; k++) {
//                if (a[i] < b[j] && b[j] < c[k]) {
//                    res++;
//                }
//            }
//        }
//    }
//    cout << res << endl;
//    return 0;
//}

