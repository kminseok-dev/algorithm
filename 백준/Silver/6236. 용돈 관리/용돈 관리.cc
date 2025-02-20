#include <bits/stdc++.h>

using namespace std;
int arr[100001];
int main(){
    int n,m,mid;
    cin>>n>>m;
    int st=1, en=0;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        en +=arr[i];
    }
    st = *max_element(arr+1,arr+n+1);
    while(st<=en){
        mid = (st+en)/2;
        int sum = mid, cnt = 1;
        for(int i=1;i<=n;i++){
            sum -= arr[i];
            if(sum<=0){
                
                sum = mid - arr[i];
                cnt++;

            }
        }
        if(cnt>m){
           // cout<< mid<< ' '<<cnt<<'\n';
            st = mid + 1;
        }
        
        else{
            en = mid - 1;

        }
    }
    cout<<mid;
}