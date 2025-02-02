#include <bits/stdc++.h>
#define FOR(i,j) for(int i=1;i<=j;i++)
using namespace std;

int arr[1001];
int d[1001][1001];
int main(){
    int n,ans=0;
    cin>>n;
    
    FOR(i,n){
        cin>>arr[i];
        d[i][1] = arr[i];
        d[i][2]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(arr[j]<arr[i]){
                if(d[i][1]<=d[j][1]+arr[i]){
                    if(d[i][2]<=d[j][2]){
                        d[i][1] = d[j][1]+arr[i];
                        d[i][2] = d[j][2]+1;
                    }
                }
                
            }
        }
    }
    FOR(i,n){
        ans = max(ans,d[i][1]);
    }

    cout<<ans;
}