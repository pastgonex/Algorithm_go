#include <iostream>

using namespace std;

int a, b;
int main()
{
    cin >> a >> b;
    int year = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        year++;
    }
    cout << year << endl;
    return 0;
}