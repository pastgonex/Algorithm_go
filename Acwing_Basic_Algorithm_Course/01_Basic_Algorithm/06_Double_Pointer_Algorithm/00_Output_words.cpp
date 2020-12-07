//
// Created by Genes on 2020/12/3.
//
// 输出单词

#include<iostream>
#include<string>

using namespace std;

const int N = 1e5 + 10;

//char str[N];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    getline(cin, str);

    for (int i = 0; i < str.size(); i++) {
        int j = i;
        while (j < str.size() && str[j] != ' ') {
            j++;
        }
        for (int k = i; k < j; k++) {
            cout << str[k];
        }
        cout << endl;
        i = j;
    }
    return 0;
}