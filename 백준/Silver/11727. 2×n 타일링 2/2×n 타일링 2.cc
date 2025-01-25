#include <bits/stdc++.h>
#define FOR(i,j) for(int i=3;i<=j;i++)

using namespace std;
int arr[1005];
int main(){
    int n;
    cin>>n;
    arr[1] = 1; arr[2] = 3;
    FOR(i,n){
        arr[i] = (arr[i-1]+2*arr[i-2])%10007;
    }
    cout<<arr[n]<<endl;
}