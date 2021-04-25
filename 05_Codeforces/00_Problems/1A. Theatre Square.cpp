/*
思路:
    if a|n , n = a
    else     n = a+,

    m同理
    总数为 n*m
*/
#include <iostream>

using namespace std;

typedef long long ll;
ll n, m, a;

void judge(ll& n, ll& a)
{
    if (n % a == 0) {
        n /= a;
    }
    else {
        n = n / a + 1;
    }
}

int main()
{
    cin >> n >> m >> a;
    judge(n, a), judge(m, a);
    cout << n * m << endl;
    return 0;
}