#include <iostream>

using namespace std;

typedef long long ll;

ll n;

bool is_lucky(int x)
{
    if(!x){
        return false;
    }
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

int main()
{
    cin >> n;
    int cnt = 0;
    while (n) {
        if (n % 10 == 4 || n % 10 == 7) {
            cnt++;
        }
        n /= 10;
    }

    puts(is_lucky(cnt) ? "YES" : "NO");

    return 0;
}