#include <bits/stdc++.h>

using namespace std;
int sequence[1000002];
vector<int> dp;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sequence[i];
    }

    for(int i=0;i<n;i++){
        auto it = lower_bound(dp.begin(),dp.end(),sequence[i]);
        
        if(it == dp.end()){
            dp.push_back(sequence[i]);
        }
        else{
            *it = sequence[i];
        }

        
        
    }
    
    cout << dp.size();
    
}
