// 统计1的数量即可
#include <iostream>

using namespace std;

int n, res;

int main()
{
    cin >> n;
    while (n--) {
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            int x;
            cin >> x;
            if (x == 1) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}