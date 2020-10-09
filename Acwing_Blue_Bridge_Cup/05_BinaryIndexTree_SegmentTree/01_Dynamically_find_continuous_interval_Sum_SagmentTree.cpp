//
// Created by Genes on 2020/10/6.
//
// 动态求连续区间和
// 线段树写法
/*
todo
 线段树的建树
    build:
        给定一个长度为N的序列A, 我们可以在区间 [1,N]上建立一颗线段树, 每个月节点[i,i]保存A[i]的值
    线段树的二叉树结构, 可以很方便地从下往上传递信息
    以区间中所有数的和为例:
        记 dat(l,r) 等于sum(l,r){A[i]}  (l<=i<=r), 显然dat(l,r)=sum(dat(l,mid),dat(mid+1,r))
    *****************************************************************************************
    以区间中所有数的最大值问(区间最大值)题为例:
        记dat(l,r)等于max(l<=i<=r){A[i]}, 显然 dat(l,r)=max(dat(l,mid),dat(mid+1,r))
    *****************************************************************************************
    调用入口都是 build(1,1,n);
    *****************************************************************************************
    编号为x的节点,  左儿子: 2x  x<<1   右儿子 2x+1 x<<1|1

todo
 线段树的单点修改
    change/modify:
        单点修改是形如 "C x v" 的指令, 表示把A[x]的值修改为v
        在线段树中, 根节点(编号从为1的节点) 是执行各种指令的入口
        我们需要从根节点出发, 递归找到代表区间[x,x]的叶节点, 然后从下往上更新[x,x]以及他的所有
        祖先节点上保存的信息, 时间复杂度为 O(logN)
        调用入口, change(1,x,v);

todo
 线段树的区间查询
    ask:
        区间查询是一条形如"Q l r"的指令, 例如查询序列 A在区间[l,r]上的最大值, 即max(l<=i<=r){A[i]}:
            我们只需要从根节点开始, 递归执行一下过程:
                1. 若[l,r]完全覆盖了当前节点代表的区间, 则立即回溯, 并且该节点的dat值为候选答案
                2. 若左子节点与[l,r]有重叠部分, 则递归访问左子节点
                3. 若右子节点与[l,r]有重叠部分, 则递归访问右子节点
    调用入口: ask(1,l,r);
    ******************************************************
    查询过程会把询问区间[l,r]在线段树上分成O(logN)个节点, 求区间和


 */
// 本题中, 线段树维护的是 区间中所有数字的和
// 但是在其他题目中, 例如区间最大值问题, 那么维护的就是区间中所有数字的最大值



#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N];

struct Node {
    int l, r;
    int sum;
} t[N * 4];

void pushup(int p) {
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum; //左儿子和右儿子之和
}

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r; // 节点p代表区间[l,r]
    if (l == r) { // 叶节点
        t[p].sum = a[l];
        return;
    }
    int mid = l + r >> 1; //折半
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);//左右子节点
    pushup(p); //从下往上传递信息, 可以省略这个函数写成一条代码  t[p].sum = t[p<<1,l].sum+t[p<<1|1].sum;
}

void change(int p, int x, int v) {
    if (t[p].l == t[p].r) { //找到叶节点
//      t[p].sum = v;// 单点修改
        t[p].sum += v; //单点增加
        return;
    }
    int mid = t[p].l + t[p].r >> 1;
    if (x <= mid) {
        change(p << 1, x, v); //x属于左半区间
    } else {
        change(p << 1 | 1, x, v); //x属于右半区间
    }
    pushup(p); // 从下往上更新信息
}

int ask(int p, int l, int r) {
    if (l <= t[p].l && r >= t[p].r) { //完全包含
        return t[p].sum;
    }
    int mid = t[p].l + t[p].r >> 1;
//    int val = -(1 << 30); //负无穷大 求区间最值
    int sum = 0;//区间和
    if (l <= mid) sum = ask(p << 1, l, r);
    if (r > mid) sum += ask(p << 1 | 1, l, r);
    //区间最大值
//    if (l <= mid) val = max(val, ask(p << 1, l, r));
//    if (r > mid) val = max(val, ask(p << 1 | 1, l, r));
    return sum;
//    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int k, x, y;
    while (m--) {
        cin >> k >> x >> y;
        if (k == 0) {
            cout << ask(1, x, y) << endl;
        } else {
            change(1, x, y);
        }
    }
    return 0;
}
