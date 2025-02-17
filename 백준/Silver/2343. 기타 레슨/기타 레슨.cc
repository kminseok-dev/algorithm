#include <bits/stdc++.h>

using namespace std;
int lecture[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    int st=0,en=0,mid;
    
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> lecture[i];
        en += lecture[i];
    }
    st = *max_element(lecture+1,lecture+n+1);
    
    while(st<=en){
        mid = (st+en)/2;
        int sum = 0,cnt = 0;
        for(int i=1;i<=n;i++){
            if(sum+lecture[i]>mid){
                sum = 0;
                cnt++;
            }
            sum += lecture[i];
        }
        if(sum != 0)cnt++;
        if(cnt>m) st = mid+1;
        else en = mid-1;
    }
    cout<<st;
    return 0;
    
}