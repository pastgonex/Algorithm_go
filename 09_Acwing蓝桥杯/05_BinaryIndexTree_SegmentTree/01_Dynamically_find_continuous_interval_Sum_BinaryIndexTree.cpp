//
// Created by Genes on 2020/10/1.
//
// 动态求连续区间和
// 树状数组做法
// 满足以下性质:
/*
 * lowbit(R) 返回R二进制最右边的1及其右边所有的0   lowbit(16) = 10000  lowbit(5) = 1
    1. 每个内部节点c[x]保存以它为根的子树中的所有叶节点的和
    2. 每个内部节点c[x]的子节点个数等于lowbit(x)的位数   lowbit(16) = 10000 = 5
    3. 除树根外, 每个内部节点c[x]的父节点是c[x+lowbit(x)] c[7]---> c[7+1]=c[8]
    4. 树的深度为O(logN)
    如果N不是2的整次幂, 那么树状数组就是一个具有同样性质的森林结构

    如何分成O(logN)个小区间:
        while(x>0)
            x-lowbit(x)+1, x
            x-=lowbit(x)

    a中存原序列的和
    c[x] 存的是 序列a的区间(x-lowbit(x)+1,x]中所有数的和

    操作:
        1. 查询前缀和
            序列a中, 1-x个数的和
            int ask(int x){
                int ans = 0;
                for(;x;){
                    ans += c[x];
                    x-=lowbit(x); //直到x为0   -->  O(logN) 的时间内查询前缀和
                }
                return ans;
            }
            如果要查询区间 [l,r]中所有数的和, 只需要 ask(r)-ask(l-1)  --> 前缀和思想
        2. 单点增加
            给序列a中的某一个数a[x]+y, 同时正确维护序列的前缀和
            根据树形结构和他的性质, 只有c[x] 和他所有的祖宗节点保存的"区间和" 包含a[x]
            而任意一个节点的祖先最后只有logN个, 对他们的c值进行更新即可, 在logN的时间内执行
            void add(int x, int y){
                for(; x<=N ;x+=lowbit(x)){
                    c[x] += y;  //正确维护前缀和
                }
            }
执行所有操作之前, 我们需要对树状数组做初始化---> 针对原始序列a, 初始化一个树状数组c
为了方便:
    建立一个全为0的数组c, 然后对每个x执行add(x,a[x])  O(NlogN), 通常采用这种初始化就已经足够

    更加高效的做法是: 从小到大依次考虑每一个节点x, 借助lowbit运算扫描他的子节点并求和, 上述树形结构的每条边只会被遍历一次
    时间复杂度为O(N)
    操作:
        预处理一个前缀和数组 pre
        初始化树状数组 c
        for(int i =1;i<=n;i++){
            c[i] = pre[i] - pre[i-lowbit(i)];   // O(N);
        }
*/

#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int pre[N], c[N], a[N];
int n, m;

int lowbit(int x) {
    return x & -x;
}

void init() {
    for (int i = 1; i <= n; i++) {
        c[i] = pre[i] - pre[i - lowbit(i)];
    }
}

void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) {
        c[x] += y;
    }
}

int ask(int x) { // 查询a序列的 [1,x] 中所有数的和
    int ans = 0;
    for (; x; x -= lowbit(x)) {
        ans += c[x];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    init();

//    for (int i = 1; i <= n; i++) {
//        add(i, a[i]);
//    }

    while (m--) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 0) {
            cout << ask(y) - ask(x - 1) << endl; //前缀和思想 s(a)-s(b-1)
        } else if (k == 1) {
            add(x, y);
        }
    }
    return 0;
}