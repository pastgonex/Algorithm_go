//
// Created by Genes on 2020/12/16.
//
// 邻值查找
#include<iostream>
#include<set>
#include<bits/stdc++.h>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 1e5 + 10;

int n, a;
set<pair<int, int>> s; //值, 下标

int main() {
    ios;
    cin >> n >> a;
    s.insert({a, 1});
    for (int i = 2; i <= n; i++) {
        cin >> a;
        s.insert({a, i});
        set<pair<int, int>>::iterator it = s.find({a, i});
        pair<int, int> ans;
        ans.first = 0x3f3f3f3f;
//        ans.first = 0x3f;

        if (++it != s.end()) {
            ans = {(*it).first - a, (*it).second};
        }
        it--;
        if (it-- != s.begin() && ans.first >= a - (*it).first) {// 要找一个最接近的, 也就是差值最小的
            ans = {a - (*it).first, (*it).second};
        }
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}