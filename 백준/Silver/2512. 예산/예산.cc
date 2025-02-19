#include <bits/stdc++.h>

using namespace std;
int budget[10001];
int main(){
    int n,ans;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>budget[i];
    }
    int m;
    cin>>m;
    sort(budget+1, budget+n+1);
    int st=1, en=budget[n];
    while(st<=en){
        int mid = (st+en)/2;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum += min(mid,budget[i]);
        }
        if(sum<=m){
            ans = mid;
            st = mid+1;
        }
        else en = mid-1;        
    }
    cout<<ans;
}