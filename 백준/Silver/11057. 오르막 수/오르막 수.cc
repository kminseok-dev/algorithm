#include <bits/stdc++.h>

using namespace std;

long long arr[1005][12];

int main(){
    int n;
    int mod = 10007;
    cin>>n;
    for(int i=0;i<=9;i++){
        arr[1][i] = 1;
    }
    
    arr[1][10] = 10;
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            if(j==0)arr[i][j] = 1;
            else arr[i][j] = (arr[i-1][j]+arr[i][j-1])%mod;
            arr[i][10] +=arr[i][j];
            arr[i][10] %= mod;

        }
    }
    cout<<arr[n][10]<<'\n';
    return 0;

}   