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
void dij(string bg){
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>> q;
    q.push({0,bg});
    mp[bg]=0;
    while(!q.empty()){
        string now=q.top().second;
        int nowcnt=q.top().first;
        q.pop();
        vector<string> v= next_States(now);
        for(const auto& i:v){
            if(mp.find(i)==mp.end()||mp[i]>nowcnt+1){
                mp[i]=nowcnt+1;
                q.push({mp[i],i});
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
    dij(a);
    if(mp.find(target)==mp.end()){
        cout<<-1;
    }
    else cout<<mp[target];
}
