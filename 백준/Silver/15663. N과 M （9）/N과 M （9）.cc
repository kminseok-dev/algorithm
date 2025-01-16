#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<bool> isused;
int arr[10];
int n, m, temp ;
void func(int k){
    if(k==m){
        for(int i=0; i<m; i++)cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    int prev=-1;
    for(int i=0;i<v.size();i++){
        if(!isused[i]&&v[i]!=prev){
            arr[k] = v[i];
            isused[i] = true;
            func(k+1);
            isused[i] = false;
            prev = v[i];
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    isused.resize(n, false);
    for(int i=0;i<n;i++)cin>>v[i];
    sort(v.begin(), v.end());
    temp = v[0];
    int cnt = 1; 
    for(int i=1;i<n;i++){
        if(temp == v[i]){temp=v[i];cnt++;}

    }
    if(cnt == n){
        for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
        cout<<'\n';
        return 0;
    }
    func(0);
}