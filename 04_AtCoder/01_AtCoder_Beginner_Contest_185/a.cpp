// 发现一个性质, 答案取决与最小的那一份
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int minx = 101;
    for (int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        minx = min(minx, x);
    }
    cout << minx << endl;
    return 0;
}
