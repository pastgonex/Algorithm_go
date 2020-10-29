#include <iostream>

using namespace std;

int arr[20];

int main()
{
    int n;
    cin >> n;
    arr[1] = 1; arr[2] = 2;
    for(int i = 3;i <=15;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    cout << arr[n];

    return 0;

}
