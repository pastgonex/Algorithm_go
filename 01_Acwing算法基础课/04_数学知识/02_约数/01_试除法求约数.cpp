#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;

void get_divisors(int n)
{
    vector<int> res;

    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            res.push_back(i);

            if (i != n / i) {  // 避免 i==n/i, 重复放入 （n是完全平方数
                res.push_back(n / i);
            }
        }
    }

    sort(res.begin(), res.end());
    for (auto item : res) {
        cout << item << " ";
    }
    puts("");
}

int main()
{
    cin >> n;
    while (n--) {
        int x;
        get_divisors(x);
    }
    return 0;
}