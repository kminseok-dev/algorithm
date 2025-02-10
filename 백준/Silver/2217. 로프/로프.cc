#include <bits/stdc++.h>
#define FOR(i,j) for(int i=1;i<=j;i++)
using namespace std;
int arr[100001];



int main(){
    int n,ans=0;
    cin >> n;
    FOR(i,n){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    
    ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,arr[n+1-i]*i);
    }
        

    cout<< ans;
}