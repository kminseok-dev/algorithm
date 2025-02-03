#include <bits/stdc++.h>

using namespace std;

int coin[10005];
int value[10005];

int main(){
    int n,k,a;
    coin[0]  = 0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    coin[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=value[i];j<=k;j++){
            coin[j] = coin[j]+coin[j-value[i]];
            //cout<<j<<':'<<coin[j]<<" ";
        }
    }
    //cout<<"\n";
    cout<<coin[k];
    return 0;
}