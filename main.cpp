#include<stdio.h>

int main() {
    int i, n, m;
    for (i = 1; i <= 7; i++) {
        scanf("%d%d", &n, &m);
        if (n + m > 8) {
            printf("%d", i);
            break;
        } else if (n + m <= 8) {
            printf("0");
            break;
        }
    }
    return 0;
}