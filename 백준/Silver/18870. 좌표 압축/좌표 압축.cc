#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n+1];
    vector<int> unique;
    vector<int> temp;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        unique.push_back(arr[i]);
    }
    sort(unique.begin(),unique.end());
    
    
    for(int i=0;i<n;i++){
        if(i==0||unique[i-1]!=unique[i]){
            temp.push_back(unique[i]);
          
        }
    }
    
    for(int i=1;i<=n;i++){
        cout << lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin()<<' ';
    }
}