#include<iostream>

using namespace std;

const int N = 1e5 + 10;

//* head 表示头节点的下标
//* e[i] 表示节点 i 的值
//* ne[i] 表示节点 i 的 next 指针是多少
//* idx 存储当前已经用到了哪个节点

int head, e[N], ne[N], idx;

//* 初始化
void init() {
    head = -1;
    idx = 0;
}

//* 将 x 插到头节点
void add_to_head(int x) {
    e[idx] = x;//! 将第一个的值 变成我们插入的值
    ne[idx] = head;//! 因为是插入，所以当前的 head 是插入后的 next 指针所要指的地方
    head = idx; //! 将 head 指到 当前的头部
    idx++;//! 移到下一个
}

//*将 x 这个点 插入到下标是 k 的点后面
void add(int k, int x) {
    e[idx] = x; //! 先把 x 这个值存下来
    ne[idx] = ne[k]; //! 把新点的指针插入 k这个点指向的下一个位置
    ne[k] = idx; //! 把 k 指向 要插入节点的位置
    idx++;
}

//* 将位置 k 后面的点删除
void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main(void) {
    //todo 第k个插入的数 就是下标是 k-1的点
    ios::sync_with_stdio(false);

    int m;
    cin >> m;

    init(); //! 初始化

    while (m--) {
        int x, k;
        char op;

        cin >> op;

        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'D') {
            cin >> k;
            if (k == 0) head = ne[head];
            else remove(k - 1); //todo 下标是 k-1
        } else {
            cin >> k >> x;
            add(k - 1, x); //todo 下标是 k-1
        }

    }

    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;

    return 0;
}