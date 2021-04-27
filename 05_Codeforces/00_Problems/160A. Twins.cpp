#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;

int n;
int a[N];

int main()
{
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sum /= 2;

    sort(a, a + n);
    reverse(a, a + n);

    int res =0 ;
    for (int i = 0; i < n; i++) {
        res+=a[i];
        if(res>sum){
            res = i+1;
            break;
        }
    }
    cout<<res<<endl;
    return 0;
}