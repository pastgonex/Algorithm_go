/*
 * Project: 10_堆
 * File Created:Thursday, January 14th 2021, 10:11:58 am
 * Author: Bug-Free
 * Problem:AcWing 839. 模拟堆
 */
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int h[N];      //堆
int ph[N];     //存放第k个插入点的下标
int hp[N];     //存放堆中点的插入次序
int cur_size;  // size 记录的是堆当前的数据多少

//这个交换过程其实有那么些绕 但关键是理解 如果hp[u]=k 则ph[k]=u 的映射关系
//之所以要进行这样的操作是因为 经过一系列操作 堆中的元素并不会保持原有的插入顺序
//从而我们需要对应到原先第K个堆中元素
//如果理解这个原理 那么就能明白其实三步交换的顺序是可以互换
// h,hp,ph之间两两存在映射关系 所以交换顺序的不同对结果并不会产生影响
void heap_swap(int u, int v) {
    swap(h[u], h[v]);
    swap(hp[u], hp[v]);
    swap(ph[hp[u]], ph[hp[v]]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= cur_size && h[t] > h[u * 2])
        t = u * 2;
    if (u * 2 + 1 <= cur_size && h[t] > h[u * 2 + 1])
        t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}
void up(int u) {
    if (u / 2 > 0 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        up(u >> 1);
    }
}

int main() {
    int n;
    cin >> n;
    int m = 0;  // m用来记录插入的数的个数
                //注意m的意义与cur_size是不同的 cur_size是记录堆中当前数据的多少
                //对应上文 m即是hp中应该存的值
    while (n--) {
        string op;
        int k, x;
        cin >> op;
        if (op == "I") {
            cin >> x;
            m++;
            h[++cur_size] = x;
            ph[m] = cur_size;
            hp[cur_size] = m;
            // down(size);
            up(cur_size);
        } else if (op == "PM")
            cout << h[1] << endl;
        else if (op == "DM") {
            heap_swap(1, cur_size);
            cur_size--;
            down(1);
        } else if (op == "D") {
            cin >> k;
            int u = ph[k];  //这里一定要用u=ph[k]保存第k个插入点的下标
            heap_swap(u,
                      cur_size);  //因为在此处heap_swap操作后ph[k]的值已经发生
            cur_size--;  //如果在up,down操作中仍然使用ph[k]作为参数就会发生错误
            up(u);
            down(u);
        } else if (op == "C") {
            cin >> k >> x;
            h[ph[k]] =
                x;  //此处由于未涉及heap_swap操作且下面的up、down操作只会发生一个所以
            down(ph[k]);  //所以可直接传入ph[k]作为参数
            up(ph[k]);
        }
    }
    return 0;
}
