#include <bits/stdc++.h>

using namespace std;


vector<int> tree[10001];
vector<int> weight(10001);  
vector<vector<int>> dp(10001,vector<int>(2));
vector<int> selected;

void dfs(int node,int parent){
    dp[node][0] = 0;
    dp[node][1] = weight[node];

    for(int child:tree[node]){
        if(child==parent)continue;

        dfs(child,node);

        dp[node][0] += max(dp[child][0],dp[child][1]);
        dp[node][1] += dp[child][0];
    }
    
}
void trace(int node,int parent,bool isSelected){
    if(isSelected){
        selected.push_back(node);
        for(int child:tree[node]){
            if(child==parent)continue;
            trace(child,node,false);
        }
    }
    else{
        for(int child:tree[node]){
            if(child==parent)continue;
            if(dp[child][0]>dp[child][1])
                trace(child,node,false);
            else
                trace(child,node,true);
        }
    }
}
int main(){
    int n,w,u,v;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin >> w;
        weight[i] = w;
    }
    while(cin>>u>>v){
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1,1);
    int ans = max(dp[1][0],dp[1][1]);
    cout<<ans<<'\n';

    if(dp[1][0]>dp[1][1]){
        trace(1,1,false);
    }
    else
        trace(1,1,true);

    sort(selected.begin(),selected.end());
    for(int i:selected)
        cout<<i<<' ';
}