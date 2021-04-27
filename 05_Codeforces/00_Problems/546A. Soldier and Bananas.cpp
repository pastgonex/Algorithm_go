#include <iostream>

using namespace std;

int k, n, w;
int main()
{
    cin >> k >> n >> w;
    int t = (k + (w * k)) * w / 2;
    n >= t ? cout << 0 << endl : cout << t - n << endl;
    return 0;
}