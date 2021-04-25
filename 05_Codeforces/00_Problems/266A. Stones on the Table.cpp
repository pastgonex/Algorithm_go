#include <iostream>

using namespace std;

int n;
string str;

int main()
{
    cin >> n >> str;
    int res = 0;
    for (int i = 0; i < str.size() - 1; i++) {
        int k = i;
        while (str[k] == str[i + 1] && i + 1 <= str.size()) {
            res++;
            i++;    
        }
    }
    cout << res << endl;
    return 0;
}