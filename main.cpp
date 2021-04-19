#include <cstring>
#include <iostream>

using namespace std;

int num[10];
int main()
{
    memset(num, 2021, 10*sizeof(int));
    for (int i = 0; i < 10; i++)
        cout << num[i] << endl;
}