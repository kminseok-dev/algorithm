#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,a;
    cin >> n;
    int arr[n+1];
    vector<int> sum;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum.push_back(arr[i]+arr[j]);
        }
    }
    sort(sum.begin(),sum.end());
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(binary_search(sum.begin(),sum.end(),arr[i]-arr[j])){
                cout << arr[i];
                return 0;
            }
        }   
    }
    
}