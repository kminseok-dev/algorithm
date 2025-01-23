#include <bits/stdc++.h>
#define FOR(i,j) for(int i = 4;i<=j;i++)
using namespace std;
int arr[11];
int main(){
    
    arr[1] = 1;arr[2] = 2;arr[3] = 4;
    FOR(i,11)arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    int T;
    cin >> T;
    while(T--){
        int x;
        cin >> x;
        cout << arr[x] << '\n';
    }
    
    return 0;
}