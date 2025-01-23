#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m],arr3[n+m];
    for(int i=0;i<n;i++)cin >> arr1[i];
    for(int i=0;i<m;i++)cin >> arr2[i];
    int idx1=0,idx2=0;
    for(int i=0;i<n+m;i++){
        if(idx1==n)arr3[i] = arr2[idx2++];
        else if(idx2==m)arr3[i] = arr1[idx1++];
        else if(arr1[idx1]<arr2[idx2])arr3[i] = arr1[idx1++];
        else arr3[i] = arr2[idx2++];
    }
    for(int i=0;i<n+m;i++)cout << arr3[i]<<' ';
}
