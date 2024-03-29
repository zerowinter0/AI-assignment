#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<string> next_States(string x){
    vector<string> v;
    for(int i=0;i<=8;i++){
        if(x[i]=='x'){
            if(i>=3){
                swap(x[i],x[i-3]);
                v.push_back(x);
                swap(x[i],x[i-3]);
            }
            if(i<6){
                swap(x[i],x[i+3]);
                v.push_back(x);
                swap(x[i],x[i+3]);
            }
            if(i%3){
                swap(x[i],x[i-1]);
                v.push_back(x);
                swap(x[i],x[i-1]);
            }
            if(i%3<2){
                swap(x[i],x[i+1]);
                v.push_back(x);
                swap(x[i],x[i+1]);
            }
            break;
        }
    }
    return v;
}
map<string,int> mp;
void bfs(string bg){
    queue<string> q;
    q.push(bg);
    mp[bg]=0;
    while(!q.empty()){
        string now=q.front();
        q.pop();
        vector<string> v= next_States(now);
        for(const auto& i:v){
            if(mp.find(i)==mp.end()){
                mp[i]=mp[now]+1;
                q.push(i);
            }
        }
    }
}
signed main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    string target="12345678x";
    string a;
    for(int i=0;i<=8;i++){
        char x;
        cin>>x;
        a.push_back(x);
    }
    bfs(a);
    if(mp.find(target)==mp.end()){
        cout<<-1;
    }
    else cout<<mp[target];
}
