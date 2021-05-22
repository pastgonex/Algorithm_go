#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<char> s;
string str;

int main()
{
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            s.insert(str[i]);
        }
    }
    cout << s.size() << endl;
    return 0;
}