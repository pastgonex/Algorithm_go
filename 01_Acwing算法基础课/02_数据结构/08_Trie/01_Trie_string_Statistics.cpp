/*
 * Project: 08_Trie
 * File Created:Wednesday, January 6th 2021, 4:35:04 am
 * Author: Bug-Free
 * Problem:AcWing 835. Trie字符串统计
 */
// #include <iostream>
// #include <unordered_map>

// using namespace std;

// unordered_map<string, int> alls;

// string str;

// int n;

// int main() {
//     cin >> n;
//     while (n--) {
//         char op[2];
//         cin >> op >> str;
//         if (op[0] == 'I') {
//             alls[str]++;
//         } else {
//             cout << alls[str] << endl;
//         }
//     }
//     return 0;
// }

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int son[N][26];  //长度最长为N, 每一层有26种 a-z
int cnt[N], idx;
//将该字符串分配的一个树结构中，以下标来记录每一个字符的位置。方便之后的插入和查找。
char str[N];

int n;

void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';  //映射到0-25
        if (!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
    }
    cnt[p]++;  //以这个字符结尾的数量+1
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) {
            return 0;  //没有这个字符串
        }
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    cin >> n;
    while (n--) {
        char op[2];
        cin >> op >> str;
        if (op[0] == 'I') {
            insert(str);
        } else {
            cout << query(str) << endl;
        }
    }
    return 0;
}
