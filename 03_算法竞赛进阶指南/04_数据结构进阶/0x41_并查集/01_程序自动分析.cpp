/*
 * Project: 0x41_并查集
 * File Created:Friday, January 8th 2021, 9:13:55 pm
 * Author: Bug-Free
 * Problem:AcWing 237. 程序自动分析
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, cnt;
vector<PII> eqs, uneqs;
unordered_map<int, int> H;
int fa[N * 2];

int mapping(int x)
{
    if (H.count(x)) {
        return H[x];
    }
    return H[x] = cnt++;
}

int find(int x)
{
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cnt = 0;
        H.clear();
        eqs.clear(), uneqs.clear();
        for (int i = 0; i < n; i++) {
            int x, y, e;
            cin >> x >> y >> e;
            x = mapping(x), y = mapping(y);  //取得离散化之后的值
            if (e) {
                eqs.push_back({x, y});
            }
            else {
                uneqs.push_back({x, y});
            }
        }
        for (int i = 0; i < cnt; i++) {
            fa[i] = i;
        }

        // merge
        for (auto item : eqs) {
            fa[find(item.first)] = find(item.second);
        }

        // query
        bool flag = true;
        for (auto item : uneqs) {
            if (find(item.first) == find(item.second)) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
