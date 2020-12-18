//
// Created by Genes on 2020/12/12.
//
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

int n;

void merge(vector<PII> &interval) {
    vector<PII> ans;

    sort(interval.begin(), interval.end()); //! pair排序 优先左端点， 再以右端点排序

    int st = -1e9 - 10, ed = -1e9 - 10;  //! 只要比 -1e9 小就可以
    for (auto item:interval) {
        if (ed < item.first) //! 第一段区间一定是  ed< item.first
        {
            if (st != -1e9 - 10) ans.push_back({st, ed}); //! 第一次在这里初始化
            st = item.first, ed = item.second;//! 第一段区间从这里开始
        } else ed = max(ed, item.second);
    }//todo 这个循环结束之后还会剩下一个区间
    if (st != -1e9 - 10) ans.push_back({st, ed});  //! 如果不是空的  那我们就加上一段

    interval = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    vector<PII> interval;
    while (n--) {
        int l, r;
        cin >> l >> r;

        interval.push_back({l, r});
    }

    merge(interval);

    cout << interval.size() << endl;

    return 0;
}