// 放入一个set中， 最后set的size就是不同的字符数量
#include <iostream>
#include <map>
#include <set>

using namespace std;

string str;
map<char, int> m;
set<char> s;

bool is_odd(int x)
{
    return x % 2 == 1;
}

int main()
{
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        s.insert(str[i]);
        // m[str[i]]++;
    }
    // if(is_odd(m.size()))
    if (is_odd(s.size())) {
        puts("IGNORE HIM!");
    }
    else {
        puts("CHAT WITH HER!");
    }
    return 0;
}