//
// Created by Genes on 2020/11/26.
//
/*
  * Although the basic idea of binary search is comparatively straightforward,
  * the details can be surprisingly tricky...
    如果把数列中每个数都减去二分的值, 就转化为判定"是否存在一个长度不小于L的子段, 子段和非负。
    1. 求一个子段, 它的和最大, 没有"长度不小于L"这个限制
        动态规划-->   每次的last表示以k结尾的子序列的最大值
        每次更新last的值 last= max(last,0)+s[j]-s[i-1];

    2. 求一个子段, 它的和最大, 子段的长度不小于L
        max(a[j+1]+a[j+2]+...+a[i]) = max(sum[i]-min{sum[j])
        i-j>=f                        f<=i<=n    0<=j<=i-f
        仔细观察上面的式子可以发现, 随着i的增长, j的取值范围0~i-L每次只会增大1。
        换言之, 每次只会有一个新的取值进入 min{sum[j] 的候选集合, 所以我们没有必要每次循环枚举j,
        只需要用一个变量记录当前最小值, 每次与新的取值 sum[i-f] 取min就可以了。
        double ans = -1e10;
        double min_val = 1e10;
        for (int i = f;i<=N;i++){
            min_val = min(min_val,sum[i-f];
            ans = max(ans,sum[i]-min_val);
        }
    解决了问题2之后, 我们只需要看一下最大子段和是不是非负数(>=0), 就可以确定二分上下界的变化范围了。
 */

#include<iostream>

#define ios ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define for_1(begin, end) for (int begin = 1; begin <= end; begin++)
#define for__(begin, val, end) for (int begin = val; begin <= end; begin++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const double eps = 1e-5;

using namespace std;

double a[N], b[N], sum[N];
int n, f;

bool check(double avg) { //是否长度>=f的一段, 平均数>=avg
    for_1(i, n) {
        b[i] = a[i] - avg; //修改a数组 放入b数组
    }
    // 其实不需要b数组, 两个for 可以写成一个, 每次重新覆盖sum数组即可
    for_1(i, n) {
        sum[i] = sum[i - 1] + b[i];
    }
    double ans = -1e10, min_val = 1e10;
    // 类似于dp, 分成 n 类情况-> (右端点在1,2...n), 判断每一类
    // 只需要分别求一下每一类的最大值, 取一个max
    // 假设右端点是a[k], 那么只需要取 max{sum[k]-min{sum[1 - k-f+1]}
    //                               sum[k]-min{sum[0 - k-f]}     sum[l,r]=sum[r]-sum[l-1]
    for__(i, f + 1, n) {
        min_val = min(min_val, sum[i - f]); //  min_val 表示 sum[0~i-f] 的最小值
        ans = max(ans, sum[i] - min_val); // ans表示以i为右端点的子段的最大值
        if (ans >= 0) {// 存在长度>=f的一段, 平均数>=avg
            return true;
        }
    }
    return false;
}

int main() {
    ios;
    cin >> n >> f;

    double l = 0, r = 0;

    for_1(i, n) {
        cin >> a[i];
        r = max(r, a[i]); //二分的右端点
    }

//    double eps = 1e-5; //保留3位小数就多开2(精度

    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << int(r * 1000) << endl; //一定要是r, 虽然l和r很接近, 但还是有差距
    return 0;
}