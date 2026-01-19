#include<bits/stdc++.h>

#define ll long long
using namespace std;

ll sequence[1000003];
vector<ll> dp;
int pos[1000003];
ll lis[1000003];

int main(){

    int n;
    
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> sequence[i];
    }

    for(int i=0;i<n;i++){
        int idx = lower_bound(dp.begin(),dp.end(),sequence[i]) - dp.begin();

        if(idx == dp.size()){
            dp.push_back(sequence[i]);
        }
        else{
            dp[idx] = sequence[i];
        }
        pos[i] = idx;
    }
    
    int cur = dp.size() - 1;

    for(int i=n-1;i>=0;i--){
        if(cur == pos[i]){
            lis[cur] = sequence[i];
            cur--;
        }
    }

    cout << dp.size() << '\n'; 
    for(int i=0;i<dp.size();i++){
        cout << lis[i] << ' ';
    }
    return 0;
}