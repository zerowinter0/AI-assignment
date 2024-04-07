#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
string target="12345678x";
unordered_map<string,int> evaluated;
unordered_map<string,int> mp;
unordered_map<string,pair<string,char>> father_mp;
inline int evaluate(const string& status){
    if(evaluated.count(status)){
        return evaluated[status];
    }
    int ret=0;
    for(int i=0;i<=8;i++){
        //if(status[i]!=target[i])ret++;
        int tmp;
        if(status[i]=='x')continue;
        else tmp=status[i]-'0';
        ret+=abs((tmp-1)%3-i%3)+abs((tmp-1)/3-i/3);
    }
    evaluated[status]=ret;
    return ret;
}
inline vector<pair<string,char>> next_States(string& x){
    vector<pair<string,char>> v;
    for(int i=0;i<=8;i++){
        if(x[i]=='x'){
            if(i>=3){
                swap(x[i],x[i-3]);
                v.emplace_back(x,'u');
                swap(x[i],x[i-3]);
            }
            if(i<6){
                swap(x[i],x[i+3]);
                v.emplace_back(x,'d');
                swap(x[i],x[i+3]);
            }
            if(i%3){
                swap(x[i],x[i-1]);
                v.emplace_back(x,'l');
                swap(x[i],x[i-1]);
            }
            if(i%3<2){

                swap(x[i],x[i+1]);
                v.emplace_back(x,'r');
                swap(x[i],x[i+1]);
            }
            break;
        }
    }
    return v;
}

void A_star(string bg){
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>>q;
    q.push({0,bg});
    while(!q.empty()){
        auto now=q.top();
        q.pop();
        if(now.second==target)return;
        vector<pair<string,char>> v= next_States(now.second);
        for(const auto& tmp:v){
            string i=tmp.first;
            if(!mp.count(i)||mp[now.second]+1<mp[i]){
                mp[i]=mp[now.second]+1;
                father_mp[i]={now.second,tmp.second};
                q.emplace(mp[i]+ evaluate(i),i);
            }
        }

    }
}
bool checkLegal(string &x){
    int cnt=0;
    for(int i=0;i<=8;i++){
        for(int j=i+1;j<=8;j++){
            if(x[i]=='x'||x[j]=='x')continue;
            if(x[i]>x[j]){
                cnt++;
            }
        }
    }
    return cnt%2==0;
}
signed main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    string a;
    for(int i=0;i<=8;i++){
        char x;
        cin>>x;
        a.push_back(x);
    }
    if(!checkLegal(a)){
        cout<<"unsolvable";
        return 0;
    }
    A_star(a);
    vector<char> ans;
    string now=target;
    while(now!=a){
        ans.push_back(father_mp[now].second);
        now=father_mp[now].first;
    }
    if(mp.find(target)==mp.end()){
        cout<<"unsolvable";
    }
    else {
        while(!ans.empty()){
            cout<<ans.back();
            ans.pop_back();
        }
    }
}
