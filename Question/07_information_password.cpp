//
// Created by Genes on 2020/10/11.
//
//信息加密

#include <iostream>

using namespace std;

int main() {
    string s;

    getline(cin, s);

    for (auto &c : s)
        if (c >= 'a' && c <= 'z') c = (c - 'a' + 1) % 26 + 'a';
        else if (c >= 'A' && c <= 'Z') c = (c - 'A' + 1) % 26 + 'A';

    cout << s << endl;

    return 0;
}