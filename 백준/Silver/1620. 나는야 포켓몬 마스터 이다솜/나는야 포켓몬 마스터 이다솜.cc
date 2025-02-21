#include <bits/stdc++.h>

using namespace std;
string Mon[100003];
unordered_map<string, int> Dogam;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> Mon[i];
        Dogam[Mon[i]] = i;
    }
    string s;
    while(m--){
        cin >> s;
        if(isdigit(s[0])){
            cout<<Mon[stoi(s)] << '\n';
        }
        else{
            cout<<Dogam[s] << '\n';
        }
    }
    return 0;
}