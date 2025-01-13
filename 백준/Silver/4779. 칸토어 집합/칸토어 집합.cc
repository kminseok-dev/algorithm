#include <bits/stdc++.h>

using namespace std;
vector<char> v;
vector<char> temp;

void Canto(long long x,long long n){
    if(n==1)return;
    n/=3;
    for(long long i=x+n;i<x+2*n;i++) v[i] = ' ';
    
    Canto(x,n);
    Canto(x+2*n,n);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    
    while(cin >> n){
    long long vren = 1;
    for (int i = 0; i < n; i++) vren *= 3;
    
    v.assign(vren, '-');
    Canto(0,vren);
    for(long long i=0; i<v.size(); i++)cout<<v[i];
    cout<< '\n';
    
    }
    return 0;
}