#include <bits/stdc++.h>
#define FOR(i,j) for(int i=1;i<=j;i++)

using namespace std;
int arr[10005];// 각 와인의 양 
int maxwine[10005]; //현재 와인을 마실때 가장 최대로 마신 양을 저장할 배열
int main(){
    int n;
    cin>>n;
    
    FOR(i,n)cin >> arr[i];
    maxwine[1]= arr[1];
    maxwine[2]= arr[1]+arr[2];
    maxwine[3]= max(arr[1],arr[2])+arr[3];
    for(int i=4;i<=n;i++){
        maxwine[i] = max(arr[i-1]+max(maxwine[i-3],maxwine[i-4]),maxwine[i-2])+arr[i];

    }
    int ans = maxwine[1];
    FOR(i,n){
        if(ans<maxwine[i])ans = maxwine[i];
       // cout<<maxwine[i]<<endl;
    }
    cout<<ans<<endl;
}