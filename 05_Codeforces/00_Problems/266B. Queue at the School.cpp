#include <iostream>

using namespace std;

int n, k;
string str;

int main()
{
    cin >> n >> k;
    cin >> str;
    while (k--) {
        for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] == 'B' && str[i + 1] == 'G') {
                swap(str[i], str[i + 1]);
                i++;
            }
        }
    }
    cout<<str<<endl;

    return 0;
}