#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], q[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int len = 0;  // 最开始， 当前的最大长度 ， 也就是q中的元素个数
    q[0] = -2e9;
    for (int i = 0; i < n; i++) {  // 枚举一下每个数
        int l = 0, r = len;
        while (l < r) {  // 找到一个 <a[i] 的最大的数
            int mid = (l + r + 1) >> 1;
            if (q[mid] < a[i]) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        len = max(len, r + 1);  // 通过r+1去更新上升子序列的最大值
        q[r + 1] = a[i];  // 找到的 q[r] 一定是 < a[i]的最大值， 因为把 a[i]拼在后面， 那么长度为 r+1 的子序列的最后一个值一定是a[i];
    }
    cout << len << endl;
    return 0;
}