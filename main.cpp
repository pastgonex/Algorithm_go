#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e4+10;

int n;
int dp[N],f[N];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    //处理边界
    dp[1] = f[1];
    for(int i=2;i<=n;i++){
        dp[i] = max(f[i],dp[i-1]+f[i]);
    }
    int k = 1;
    for(int i=2;i<=n;i++){
        if(dp[i]>dp[k]){
            k = i;
        }
    }
    cout<<dp[k]<<endl;
    return 0;
}