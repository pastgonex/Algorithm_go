//
// Created by Genes on 2020/10/13.
//
// 交换瓶子
// k个环--> n个环
/*
 情况:
    1. 一个环中的两个节点交换--> 分裂成两个
    2. 两个环中的两个节点交换--> 合成一个环

    k个环--> n个环 (自环)
    最少需要 n-k个操作, 所以答案就是n-k
 */

#include<iostream>

using namespace std;

const int N = 1e4 + 5;

int n;
int b[N];
bool st[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int cnt = 0; //环的数量
    for (int i = 1; i <= n; i++) {
        if (!st[i]) { //如果没有标记过, 说明这个点在一个新的环中
            cnt++; //环++
            // 把这个点能到的所有点全部标记一下
            // 1 2 3 4 5
            // 3 1 2 5 4
            // 3指向2  j=b[3]=2
            // 2指向1  j=b[2]=1
            // 1指向3  j=b[1]=3;
            // 3指向2  j=b[3]=2 -->被标记过了
            // s[2] s[3]
            // s[4] s[4]=true  4指向5 j=b[4]=5
            //      s[5]=true  5指向4 j=b[5]=4;
            // 一共两个环
            for (int j = i; !st[j]; j = b[j]) {//走完这个环 每次变更指向b[j] 即瓶子初始序号的第j个
                st[j] = true;
            }
        }
    }
    cout << n - cnt << endl;
    return 0;
}
