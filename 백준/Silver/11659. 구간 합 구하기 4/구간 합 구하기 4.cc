#include <bits/stdc++.h>
#define FOR(i,j) for(int i=1;i<=j;i++)

using namespace std;
int arr[100001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    
    FOR(i,n){
        cin >> a;
        arr[i]  = arr[i-1]+a; 
    } 
    FOR(i,m){
        cin >> a >> b;
        cout<<arr[b] - arr[a-1]<<'\n';
    }
}