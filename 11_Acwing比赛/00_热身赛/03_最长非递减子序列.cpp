/*
    思路：
        翻转之前一定是 1111  【2222 1111】 2222
        每一段的长度可以为0 ， 但是一定翻转的是中间这一段
    只需求出， 前一段长度最大是多少，前两段， 前三段.....

*/
#include <algorithm>
#include <iostream>

using namespace std;

int n;

int main()
{
    scanf("%d", &n);

    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;

    while (n--) {
        int x;
        cin >> x;
        if (x == 1) {
            s1++;
            s3 = max(s3 + 1, s2 + 1);
        }
        else {
            s2 = max(s1 + 1, s2 + 1);
            s4 = max(s3 + 1, s4 + 1);
        }
    }

    printf("%d\n", max(s3, s4));

    return 0;
}