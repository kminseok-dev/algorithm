#include <bits/stdc++.h>

using namespace std;

vector<string> v;
map<string,int> lamp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    string str;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>str;
        v.push_back(str);
    }
    int Switch;
    cin>>Switch;
    
    for(auto i:v){
        int zero = 0;
        for(auto j:i){
            if(j=='0') zero++;
        }
        if(zero>Switch||zero%2!=Switch%2)continue;
        if(lamp.find(i) == lamp.end()){
            lamp.insert(make_pair(i,1));
        }
        else lamp[i]++;
    }
    int ans = 0;
    for(auto i:v){
        ans = max(ans, lamp[i]);
    }
    cout<<ans;
    return 0;
}