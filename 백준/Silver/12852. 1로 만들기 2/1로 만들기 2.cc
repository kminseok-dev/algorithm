#include <bits/stdc++.h>
#define FOR(i,j) for(int i = 3; i <=j; i++)

using namespace std;
int arr[1000010];
int pre[1000010];
int main(){
    int n;
    cin >> n;
    arr[2] = 1;
    pre[2] = 1;
    FOR(i,n){
        arr[i] = arr[i-1]+1;
        pre[i] = i-1;
        if(i%3==0&&arr[i]>arr[i/3]+1){
            arr[i] = arr[i/3]+1;
            pre[i] = i/3;
        }
        if(i%2==0&&arr[i]>arr[i/2]+1){
            arr[i] = arr[i/2]+1;
            pre[i] = i/2;
        }
         
    }
    int cur = n;
    cout<<arr[n]<<'\n';
    while(1){
        cout<<cur<<" ";
        if(cur==1)break;
        cur = pre[cur];
    }
}
