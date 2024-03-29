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
set<string> st;
void dfs(string bg){
    deque<string> q;
    q.push_back(bg);
    while(!q.empty()){
        string now=q.back();
        q.pop_back();
        vector<string> v= next_States(now);
        for(const auto& i:v){
            if(st.find(i)==st.end()){
                st.emplace(i);
                q.push_back(i);
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
    dfs(a);
    if(st.find(target)!=st.end())cout<<"1";
    else cout<<"0";
}
