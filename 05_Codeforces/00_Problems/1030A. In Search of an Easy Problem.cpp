#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    bool flag = false;
    while (n--) {
        int x;
        cin >> x;
        if (x) {
            flag = true;
        }
    }
    if (flag) {
        puts("HARD");
    }
    else {
        puts("EASY");
    }
    return 0;
}