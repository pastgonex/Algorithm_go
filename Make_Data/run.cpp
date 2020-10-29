// #include<bits/stdc++.h>
#include<ctime>
#include<iostream>
#include <windows.h>

using namespace std;

int main() {
    for (/*register*/ int i = 1; i <= 15; i++) { //! 这个程序是用标程(solve.cpp)跑对应的in出out
        char s[500];
        sprintf(s, "solve.exe<%d.in>%d.out", i, i);
        int cl = clock();
        system(s);
        printf("%d ms\n", clock() - cl);
    }
    return 0;
}
