#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 2e1;

typedef long long ll;

int n, m;
int p[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    int res =0 ;
    for (int i = 1; i < 1 << m; i++) {
        int t = 1, cnt = 0;
        for (int j = 0; j < m; j++) {
            if (i >> j & 1) {
                if ((ll)t * p[j] > n) {
                    t = -1;
                    break;
                }
                cnt++;
                t *=p[j];
            }
        }
        if (t != -1) {
            if (cnt & 1) {
                res += n / t;
            }else{
                res -= n/t;
            }
        }
    }
    cout<<res<<endl;
}
