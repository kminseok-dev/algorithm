#include <bits/stdc++.h>

using namespace std;
int arr[1001][2];
vector<int>Combi(1005,0Xffffff);
int ans, n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i][0];
        arr[i][1] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[j][0]>arr[i][0]){
                if(arr[j][1]<=arr[i][1]){
                    arr[j][1] = arr[i][1]+1; 
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans = max(ans,arr[i][1]);
    }
    cout<<ans<<'\n';
    int end = ans;
    for(int i=n;i>=1;i--){
        if(arr[i][1]==ans&&(Combi[ans+1]>arr[i][0])){
            Combi[ans] = arr[i][0];
            ans--;
            //cout<<Combi[ans+1]<<' ';
        }
    }
    for(int i=1;i<=end;i++){
        cout<<Combi[i]<<' ';
    }
    

    return 0;
}