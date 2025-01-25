#include <bits/stdc++.h>
#define FOR(i,j) for(int i=2;i<=j;i++)
using namespace std;
int arr[1000001];
int x;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> x; 
    FOR(i,x){
        arr[i]=arr[i-1]+1;
        if(i%3==0)arr[i] = min(arr[i],arr[i/3]+1);
        if(i%2==0)arr[i] = min(arr[i],arr[i/2]+1);
    }
    cout<< arr[x];

}