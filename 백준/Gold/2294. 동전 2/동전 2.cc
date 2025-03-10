    #include <bits/stdc++.h>

    using namespace std;


    int value[10005];

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n,k,a;
        cin>>n>>k;
        vector<int> coin(10005,2*k);
        coin[0] = 0;
        
        for(int i=1;i<=n;i++){
            cin>>value[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=value[i];j<=k;j++){
                coin[j] = min(coin[j],coin[j-value[i]]+1);
            }
        }
        //for(int i=0;i<=k;i++){cout<<coin[i]<<'\n';}
        if(coin[k]==2*k){cout<<-1;return 0;}
        cout<<coin[k];
    }