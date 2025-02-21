#include <bits/stdc++.h>

using namespace std;
set<string> s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string name, log;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>name >> log;
        if(log=="enter"){
            s.insert(name);
        }
        else{
            s.erase(name);
        }
    }
    vector<string> company(s.begin(),s.end());
    sort(company.begin(),company.end(),greater<string>());
    for(auto i:company){cout<<i<<'\n';}
    return 0;

        
}