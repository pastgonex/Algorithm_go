#include <cstdio>

#define P(item) printf("%s =  %d\n", #item, item);

#define MAX(a, b) ({    \
    __typeof(a) _a = a; \
    __typeof(b) _b = b; \
    _a > _b ? _a : _b;  \
})

int main(void)
{
    int a = 6;
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(9, MAX(2, MAX(1, 2))));
    P(MAX(a++, 7));
    P(a);
    return 0;
}
