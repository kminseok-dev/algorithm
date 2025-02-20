#include <bits/stdc++.h>

using namespace std;
int arr[100001];
int main(){
    int n,m,ans=2000000000;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int en = 1;
    sort(arr+1,arr+n+1);
    for(int st = 1;st<=n;st++){
        while(en<=n&&arr[en]-arr[st]<m)en++;
        if(arr[en]-arr[st]>=m){
            ans = min(ans,arr[en]-arr[st]);
        }
    }
    cout<<ans;
}