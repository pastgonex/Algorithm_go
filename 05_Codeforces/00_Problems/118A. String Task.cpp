#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> vowels;

char v[12] = {'a', 'A', 'o', 'O', 'y', 'Y', 'e', 'E', 'u', 'U', 'i', 'I'};
string a;

int main()
{
    for (int i = 0; i < 12; i++) {
        vowels[v[i]]++;
    }

    cin >> a;

    for (int i = 0; i < a.size(); i++) {
        if (!vowels.count(a[i])) {
            if ('A' <= a[i] && a[i] <= 'Z') {
                a[i] += 32;
            }
            cout << '.' << a[i];
        }
    }
    cout << endl;
    return 0;
}