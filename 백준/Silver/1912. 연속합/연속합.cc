#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int arr[100005];
    int dp[100005];
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        dp[i] = 0;
    }

    int result = -2e9;
    for(int i=1;i<=n;i++){
       dp[i] = max(arr[i],dp[i-1]+arr[i]);
       result = max(result,dp[i]);
    }
    cout<<result;
    return 0;
}