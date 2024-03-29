#include<bits/stdc++.h>
#define default_int (10000*(n+5))
using namespace std;
int step[1000][1000];
bool vis[1000];
void bad_dijkstra(int n){
    while(1){
        int now=-1;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&(now==-1||step[1][i]<step[1][now])&&step[1][i]<default_int){
                now=i;
            }
        }
        if(now==-1)break;
        vis[now]=true;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                step[1][i]=min(step[1][i],step[1][now]+step[now][i]);
            }
        }
    }
}
signed main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)step[i][j]=default_int;
        }
    }
    for(int i=1;i<=m;i++){
        int x,y,value;
        cin>>x>>y>>value;
        step[x][y] = min(step[x][y], value);
    }
    bad_dijkstra(n);
    if(!vis[n]){
        cout<<-1;
    }
    else cout<<step[1][n];
}
