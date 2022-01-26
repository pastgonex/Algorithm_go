#include <iostream>

using namespace std;

int main(void)
{
    for (int i = 0, j = 0; i < 51; i++, j += 2)
        printf("%d ", j);
    puts("");
    return 0;
}

/*
for(int i=0;i<=100;i++)
    if(i%2==0) printf("%d ",i);
puts("");
*/
