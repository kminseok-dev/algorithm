#include<bits/stdc++.h>
#define FOR(i,j) for(int i=1;i<=j;i++)
using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,result=0;
    cin>>n>>m;
    string s;
    FOR(i,n){
        cin>>s;
        FOR(j,m){
            if(s[j-1] == '0') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    FOR(i,n){
        FOR(j,m){
            if(arr[i][j]!=0){
                dp[i][j] = min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
                result = max(result,dp[i][j]);
            }
        }
    }
  
    
    cout<<result*result;
    return 0;
}