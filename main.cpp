#include <iostream>
using namespace std;

char g[10][10];

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            g[i][j] = '.';
        }
    }
    for (int i = 1; i <= 5; i++) {
        puts(g[i]);
    }
    return 0;
}
