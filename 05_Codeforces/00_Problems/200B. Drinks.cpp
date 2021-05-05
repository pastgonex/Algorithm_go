#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    int t = n;
    double res = 0;
    while (t--) {
        double x;
        cin >> x;
        res += x / n;
    }
    cout << res << endl;
    return 0;
}