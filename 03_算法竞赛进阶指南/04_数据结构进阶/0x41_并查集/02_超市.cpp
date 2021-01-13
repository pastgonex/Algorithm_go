/*
 * Project: 0x41_并查集
 * File Created:Saturday, January 9th 2021, 12:01:03 pm
 * Author: Bug-Free
 * Problem:AcWing 145. 超市
 */
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int n, fa[N];

pair<int, int> p[N];

int get(int x) {
    if (x == fa[x]) {
        return x;
    }

    return fa[x] = get(fa[x]);  //路径压缩, 把这个集合中所有的 都指向根
}

void Supermarket() {
    int d = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        d = max(d, p[i].second);  //取得一个最大天数
    }
    sort(p + 1,
         p + n + 1);  // 按照利润从小到大做一个排序, 后面倒着处理就好(从大到小)

    for (int i = 0; i <= d; i++) {  //起初每一天各自构成一个集合
        fa[i] = i;
    }

    //    利用路径压缩, 可以快速找出从过期时间往前数第一个空闲的天数
    for (int i = n; i; i--) {      //从利润大的开始(从后往前)
        int r = get(p[i].second);  //获取利润最大的商品的过期日期
        if (r) {                   //如果这个"位置"还没有被用掉
            ans += p[i].first;     //更新答案
            //合并两个集合(r与r-1)-> 把这个"位置"指向他前一个"位置"
            fa[r] = r - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    while (cin >> n) {
        Supermarket();
    }
    return 0;
}
