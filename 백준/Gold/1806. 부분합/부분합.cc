#include <bits/stdc++.h>
#define FOR(i,j) for(int i=1; i<=j; i++)
using namespace std;
int arr[100001];
int main(){
    int n,m,ans=0x7fffffff,en=1;
    cin>>n>>m;
    FOR(i,n)cin>>arr[i];
    int sum = 0;
    FOR(st,n){
        while(en<=n&&sum<m){
            sum += arr[en];
            en++;
            
        }
        if(sum>=m){
            //cout<< en <<' ' <<st <<'\n';
            ans = min(ans,en-st);    
        }
        sum -= arr[st];
        
    }
    // int start=0, end=0;
    // while(end<=n) {
    //     if(sum[end]-sum[start]>=m) {
    //         ans = min(ans, end-start);
    //         start++;
    //     }
    //     else end++;
    // }
    if(ans==0x7fffffff){
        cout<<0;
        return 0;
    }
    cout<<ans;
}