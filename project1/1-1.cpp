#include<bits/stdc++.h>
using namespace std;
vector<int> sons[100005];
bool vis[100005];
int step[100005];
void bfs(int n){
    vis[1]=true;
    if(1==n)return;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(auto i:sons[now]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
                step[i]=step[now]+1;
                if(i==n)return;
            }
        }
    }
}
signed main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        sons[x].push_back(y);
        sons[y].push_back(x);
    }
    bfs(n);
    if(!vis[n]){
        cout<<-1;
    }
    else cout<<step[n];
}
