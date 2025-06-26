#include <bits/stdc++.h>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int  n,k,a,ans=0;
    vector<int> budget;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin >> a;
        budget.push_back(a);
    }
    int idx = n-1;
    int remain=k;
    while(idx>=0){
        if(remain==0){
            break;
        }
        if(budget[idx]<=remain){
            ans++;
            remain -= budget[idx];
            continue;     

        }
        idx--;
        
    }
    cout << ans;
}