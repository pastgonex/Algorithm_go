/*
 * Project: 0x12_Queue
 * File Created:Friday, January 1st 2021, 13:31:39 pm
 * Author: Bug-Free
 * Problem:AcWing 134. 双端队列
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 10;

typedef pair<int, int> PII;

#define value first
#define before_sort second

PII a[N];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].value;
        a[i].before_sort = i;
    }
    sort(a, a + n);
    int res = 1;  // 最后最少分成的段数
    // last记录一下上一个值(上一段的最后一个值是多少),
    // 初始化为比所有坐标都大即可(>n的数字均可) dir用来记录方向
    // 第一条边一定是下降的, 因此dir初始化为-1(可以理解为是从上面接下来的)
    for (int i = 0, last = n + 1, dir = -1; i < n;) {
        int j = i + 1;
        // 找到一段相等的数值
        // 如果这一段的数字是相等的, 那么这些下标是可以随意变换的
        // 从i-j-1这一段, 都是和a[i].value相同的数字
        while (j < n && a[j].value == a[i].value) {
            j++;
        }
        // 找到这一段中的最大的下标和最小的下标
        // 因为是sort(pair经过sort)过的, 因此minx一定这一段的第一个数的位置
        // maxx一定是这一段的最后一个数的位置
        // 在原序列中的的位置
        // minx=a[i].before_sort, maax = a[j-1].before_sort;
        // 我们处理的时候是一个点一个点进行处理的(如果有相同的, 则处理一段,
        // 因为相同的可以任意插入到一个双端队列)
        int minx = a[i].before_sort, maxx = a[j - 1].before_sort;
        if (dir == -1) {        //如果是下降的, 如何做?
            if (last > maxx) {  //如果上一个位置>当前的最大位置,
                                //那么就可以接到上一个位置的后面
                last =
                    minx;  // 接上了的话, 这一段的最后一个数值(原坐标)应该是minx
            } else {  //如果没有接上, 那么更新方向为上升, last=maxx
                      // 此时不需要res++的原因是 谷是先下降, 后上升的
                      // 上升结束之后, 才需要开启新的谷
                dir = 1, last = maxx;  // 上升的时候last更新为最大值,
            }
        } else {  // 如果是上升的, 如何做?
            if (last <
                minx) {  // 如果last比我当前这一段的最小值还要小, 那么可以接上去
                last = maxx;
            } else {  // 否则开新双端队列+更新last为这一段的最小值,
                      // 更新方向为下降
                res++;
                last = minx;
                dir = -1;
            }
        }
        i = j;
    }
    cout << res << endl;
    return 0;
}
