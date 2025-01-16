#include <bits/stdc++.h>

using namespace std;

int arr[10];
int arr1[10];
bool isused[10];
int n,m;

void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr1[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    int pre=-1;
    for(int i=0;i<n;i++){
        if(pre!=arr[i]&&!isused[i]){
            arr1[k] = arr[i];
            if(arr1[k]<arr1[k-1])continue;
            
            isused[i] = true;
            func(k+1);
            isused[i] = false;
            pre = arr[i];
        }
    }

}
int main(){
    cin>> n>> m;
    for(int i=0;i<n;i++)cin>> arr[i];
    sort(arr,arr+n);
    func(0);
   
    
    return 0;

}