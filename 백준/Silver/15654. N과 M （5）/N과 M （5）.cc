#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<bool> isused;
int arr[10];
int n, m ;
void func(int k){
    if(k==m){
        
        for(int i=0; i<m; i++)cout<<arr[i]<<' ';
        cout<<'\n';
        
        return;
    }
    for(int i=0;i<v.size();i++){
        if(!isused[i]){
            arr[k] = v[i];
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main(){
    
    cin >> n >> m;
    v.resize(n);
    isused.resize(n, false);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(), v.end());
    func(0);
}