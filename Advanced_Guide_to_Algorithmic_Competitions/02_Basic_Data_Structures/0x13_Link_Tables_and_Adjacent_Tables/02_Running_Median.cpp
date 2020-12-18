//
// Created by Genes on 2020/12/16.
//
// 动态中位数
#include<iostream>
#include<algorithm>

#define ios                               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);                     \
    cout.tie(nullptr)

using namespace std;

const int N = 10000;

int a[N];
int ans[N];
int p, m;

struct Node {
    //数组模拟链表数据结构
    int pre, next;//前驱 后继
    int id;//在原本序列中的位置
    int num;//本身数据
} A[N];//存储数据集的链表

bool operator<(const Node &x, const Node &y) {
    return x.num < y.num;
}


void remove(int x) {
    //删除链表中位置为x的数 就将它的前驱的后继改成它的后继 它的后继的前驱改为它的前驱
    A[A[x].pre].next = A[x].next;
    A[A[x].next].pre = A[x].pre;
    A[x].pre = A[x].next = 0;
}

void solve() {
    int cnt = 0;
    sort(A + 1, A + 1 + m);//把序列从小到大排序
    for (int i = 1; i <= m; i++) {
        a[A[i].id] = i;//将序列原来位置与现在数值位置相绑定 在删除时候便可以直接找到要删除的位置
    }
    for (int i = 1; i <= m; i++) {
        A[i].pre = i - 1, A[i].next = i + 1;
    }

    int mid = (1 + m) >> 1;//求出当前中位数位置

    ans[++cnt] = A[mid].num;//直接把当前中位数记录下来 作为最后一个输出
    for (int i = m; i > 1; i -= 2) {
        //从后往前推 依次删除 每次删除两个
        int  p1= a[i], p2 = a[i - 1];//得到删除的两个数据在现在有序序列中的位置
        if (p1 > p2) {
            swap(p1, p2);//保证pos1<pos2 方便接下来的操作
        }
        if (p1 >= mid) {
            //如果被删除的pos1是中位数或者在中位数右边，由于pos2>p1 所以中位数向左移
            mid = A[mid].pre;
        } else if (p2 <= mid) {
            //如果被删除的pos2是中位数或者在中位数左边，由于pos2>p1 所以中位数向右移
            mid = A[mid].next;
        }
        //如果一左一右，那么中位数不变
        ans[++cnt] = A[mid].num;//记录当前中位数 由于是反向推 所以输出的时候也要反向输出

        //执行删除操作
        remove(p1), remove(p2);

    }
    int k = 0;
    while (cnt--) {
        ++k;
        cout << ans[cnt + 1] << " ";
        if (!(k % 10)) {
            cout << endl;
        }
    }
    if (k % 10) {
        cout << endl;
    }
}

int main() {
    ios;
    cin >> p;
    while (p--) {
        int id;
        cin >> id >> m;
        for (int i = 1; i <= m; i++) {
            cin >> A[i].num;
            A[i].id = i;//记录该数据原本在序列中的位置
        }
        cout << id << " " << (m + 1) / 2 << endl;
        solve();
    }
    return 0;
}