#include <bits/stdc++.h>
#define FOR(i,j) for(int i=3;i<=j;i++)

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[1010];
    
    arr[1] = 1;
    arr[2] = 2;
    if(n<=2) {cout<<arr[n];return 0;}
    FOR(i,n){
        arr[i] = (arr[i-1]+arr[i-2])%10007;
    }
    
   
    cout<<arr[n];
    return 0;
}