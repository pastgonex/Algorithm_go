/*
 * Project: Week02
 * File Created:Sunday, January 17th 2021, 12:05:07 am
 * Author: Bug-Free
 * Problem:AcWing 429. 奖学金
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 3e2 + 10;

struct info {
    int c, m, e, id, t;  //语数英成绩，学号和总分
} a[N];

bool cmp(info x, info y) {
    if (x.t == y.t) {
        if (x.c == y.c) {
            return x.id < y.id;
        } else {
            return x.c > y.c;
        }
    }
    return x.t > y.t;
}

int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].c >> a[i].m >> a[i].e;
        a[i].id = i;
        a[i].t = a[i].c + a[i].m + a[i].e;  //总分
    }

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= 5; i++) {
        cout << a[i].id << " " << a[i].t << endl;
    }
    return 0;
}
