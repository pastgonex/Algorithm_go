#include <stdio.h>
void func(int *a, int *b, int c) {
    a[3] = 6;
    b[0] = 2;
    c = 7;
}

int main() {
    int a[10] = {0}, b = 45, c = 67;
    func(a + 1, &b, c);
    printf("%d %d %d\n", a[3], b, c);
    return 0;
}
