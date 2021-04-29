#include <iostream>

using namespace std;

int n;
string feel[2] = {"I love ", "I hate "};

int main()
{
    cin >> n;
    string res = "";
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            res += "that ";
        }
        res += feel[i & 1]; 
    }
    res+="it";
    cout << res << endl;
}