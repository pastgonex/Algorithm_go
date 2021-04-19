#include <iostream>

using namespace std;

int n, m;
int ans;

// void dfs(int x,int y){
//     if(x==n&&y==m){
//         ans++;
//         return ;
//     }
//     // 往右的分支
//     if(y<m) dfs(x, y+1);

//     // 往下的分支
//      if(x<n) dfs(x+1, y);

// }
// int dfs(int n,int m){
//     if(n==0&& m==0){
//         return 0;
//     }
//     if(n==0){
//         return 1;
//     }
//     if(m==0){
//         return 1;
//     }
//     return dfs(n-1,m)+ dfs(n,m-1);
// }

int dfs(int x, int y)
{
    if (x == n && y == m) {
        ans++;
    }

    if (x < n) {
        dfs(x + 1, y);
    }
    if (y < m) {
        dfs(x, y + 1);
    }

    return ans;
}

int main()
{
    cin >> n >> m;
    // dfs(0,0);
    cout << dfs(0, 0) << endl;
    return 0;
}