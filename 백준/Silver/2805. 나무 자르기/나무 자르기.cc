#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll arr[1000001];
int main(){
    ll n,m,ans;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    ll st=0,en=arr[n];
    while(st<=en){
        ll mid = (st+en)/2;
        ll sum=0;
        for(ll i=1;i<=n;i++){
            if(arr[i]>mid){
                sum += arr[i]-mid;
            }
        }
        if(sum>=m){st=mid+1;ans=mid;}
        else if(sum<m)en = mid-1;
        
    }
    cout<<ans;
    
    
}