#include <iostream>

using namespace std;

int n;
int cnt[5];

int main()
{
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int res = 0;
    if (cnt[4]) {
        res += cnt[4];
        cnt[4] = 0;
    }
    if (cnt[3] && cnt[1]) {
        int t = min(cnt[3], cnt[1]);
        res += t;
        cnt[3] -= t, cnt[1] -= t;
    }
    if (cnt[2] >= 2) {
        res += cnt[2] / 2;
        if (cnt[2] & 1) {
            cnt[2] = 1;
        }
        else {
            cnt[2] = 0;
        }
    }
    if (cnt[3]) {
        res += cnt[3];
        cnt[3] = 0;
    }
    if (cnt[1] >= 4) {
        res += cnt[1] / 4;
        cnt[1] -= cnt[1] / 4 * 4;
    }
    if (cnt[2] && cnt[1]) {
        cnt[2] = 0;
        if (cnt[1] > 2) {
            cnt[1] -= 2;
        }
        else {
            cnt[1] = 0;
        }
        res++;
    }
    if (cnt[2]) {
        cnt[2] = 0;
        res++;
    }
    if (cnt[1]) {
        res++;
        cnt[1] = 0;
    }
    cout << res << endl;

    return 0;
}