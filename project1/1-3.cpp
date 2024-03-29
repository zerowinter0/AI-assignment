#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> sons[150005];
bool vis[150005];
int step[150005];
void dijkstra(int n){
    vis[1]=true;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
    q.emplace(0,1);
    while(!q.empty()){
        auto now=q.top();
        q.pop();
        for(auto i:sons[now.second]){
            if(!vis[i.first]||step[i.first]>step[now.second]+i.second){
                vis[i.first]=true;
                step[i.first]=step[now.second]+i.second;
                q.emplace(step[i.first],i.first);
            }
        }
        while(!q.empty()&&q.top().first>step[q.top().second]){
            q.pop();
        }
    }
}
signed main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,value;
        cin>>x>>y>>value;
        sons[x].emplace_back(y,value);
    }
    dijkstra(n);
    for(int i=1;i<=n;i++){
        cout<<step[i]<<" ";
    }
}
