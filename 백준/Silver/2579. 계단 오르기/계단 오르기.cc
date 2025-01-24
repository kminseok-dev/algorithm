#include <bits/stdc++.h>
#define FOR(i,j) for(int i=3;i<=j;i++)
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[301];
    int arr1[301][3];
    for(int i=1;i<=n;i++) cin >> arr[i];
    if(n==1){cout<< arr[1];return 0;}

    arr1[1][1] = arr[1];
    arr1[1][2] = 0;
    arr1[2][1] = arr[2];
    arr1[2][2] = arr[1]+arr[2];

    FOR(i,n){
        arr1[i][1] = max(arr1[i-2][1],arr1[i-2][2])+arr[i];
        arr1[i][2] = arr1[i-1][1]+arr[i];
    }
    cout<< max(arr1[n][1],arr1[n][2]);
    return 0;
}