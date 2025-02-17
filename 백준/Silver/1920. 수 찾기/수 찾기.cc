#include <bits/stdc++.h>

using namespace std;
int arrN[100001];
int n;
int search(int k){
    int st = 1, en = n;
    while(st<=en){
        int mid = (st+en)/2;
        if(arrN[mid]>k){
            en = mid-1;
        }
        else if(arrN[mid]<k){
            st = mid+1;
        }
        else return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arrN[i];
    }
    sort(arrN+1,arrN+n+1);
    int m,target;
    cin>>m;

    for(int i=1;i<=m;i++){
        cin>>target;
        cout<<search(target)<<'\n';
    }
    
    
}