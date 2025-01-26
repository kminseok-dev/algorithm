    #include <bits/stdc++.h>
    #define FOR(i,j) for(int i=2;i<=j;i++)

    using namespace std;
    int arr[105][11];
    //arr[n][0~9] 끝자리가 0~9인 n자리의 계단수 개수 mod 1000000000
    //arr[n][10] n자리 계단수의 개수 mod 1000000000의 합
    int n,mod = 1000000000;

    int main(){
        cin>>n;
        for(int i=1;i<10;i++)arr[1][i] = 1;
        arr[1][10] = 9;
        FOR(i,n){
            for(int j=0;j<10;j++){
                if(j==0)arr[i][j] = (arr[i-1][1])%mod;
                else if(j==9)arr[i][j] = (arr[i-1][8])%mod;
                else arr[i][j] = (arr[i-1][j-1]+arr[i-1][j+1])%mod;
                arr[i][10] += arr[i][j]; 
                arr[i][10] %= mod;
            }
        }
        cout<<arr[n][10];
        
    }