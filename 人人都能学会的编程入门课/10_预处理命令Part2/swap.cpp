#include <iostream>

#define swap(a, b)             \
    {                          \
        __typeof(a) _temp = a; \
        a = b;                 \
        b = _temp;             \
    }

#define P(x) printf("%s = %d\n", #x, x);

int main(void)
{
    int a = 123, b = 456;
    swap(a, b);
    P(a);
    P(b);
    return 0;
}
