#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 5e2+10, INF= 0x3f3f3f3f;

int n,m;
int g[N][N]; //稠密图使用邻接矩阵存储
int dist[N];
bool st[N];

int prim(){
    memset(dist, 0x3f ,sizeof dist);

    int res=0; //所有边的权值和
    for(int i =0;i<n;i++){
        int t = -1;
        for(int j =1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])){
                t=j;
            }
        }
        if(i && dist[t]==INF){ //说明所有边不是联通的
            return INF;
        }

        if(i){
            res+=dist[t];
        }

        st[t]=true;

        for(int j =1;j<=n;j++){
            dist[j] = min(dist[j],g[t][j]);
        }
    }

    return res;
}

int main(){
    cin>>n>>m;

    memset(g, 0x3f, sizeof g);

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]= g[b][a]=min(g[a][b],c); //无向图, 建立双向边
    }

    int t = prim();

    if(t==INF){
        cout<<"impossible"<<endl;
    }else{
        cout<<t<<endl;
    }

    return 0;
}