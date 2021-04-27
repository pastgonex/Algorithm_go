#include <iostream>

using namespace std;

int n;
string str;

int main()
{
    cin >> n >> str;
    int cnt_a = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'A') {
            cnt_a++;
        }
    }
    if (cnt_a > n - cnt_a) {
        puts("Anton");
    }
    else if (cnt_a == n - cnt_a) {
        puts("Friendship");
    }
    else {
        puts("Danik");
    }
    return 0;
}