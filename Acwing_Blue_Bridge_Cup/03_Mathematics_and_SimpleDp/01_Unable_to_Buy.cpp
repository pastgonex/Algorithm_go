//
// Created by Genes on 2020/8/31.
//

/*
2:n+2 m+2
3:n+1 m+2
4:n+2 m+6    3: m = 2n-3
                 1 = 2*2 + x x=-3   2n-3 = m
             4: m = 3n-4
             5: m = 4n-5
             p q
             ans = (q-1)p - q

x n m
2 3 1
2 5 3
2 7 5
2 9 7
2 11 9
**********
3 2 1
3 4 5
3 5 7
3 7 11
**********
4 1 0
4 3 5
4 5 11
4 7 17
4 9 23

*/
#include<iostream>

using namespace std;

int p, q;

int main() {
    ios::sync_with_stdio(false);
    cin >> p >> q;
    cout << p * (q - 1) - q << endl;
    return 0;
}