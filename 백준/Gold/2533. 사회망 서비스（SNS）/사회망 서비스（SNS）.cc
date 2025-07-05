    #include <bits/stdc++.h>

    using namespace std;

    vector<int> tree[1000001];
    vector<vector<int>> dp(1000001,vector<int>(2));
    void dfs(int node,int parent){

        dp[node][0] = 0;
        dp[node][1] = 1;
        for(int child:tree[node]){
            if(child == parent)continue;
            dfs(child, node);
           
            dp[node][0] += dp[child][1];
            dp[node][1] += min(dp[child][0],dp[child][1]); 

        }





    }

    int main(){
        int n,u,v;

        cin >> n;

        for(int i=1;i<n;i++){
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(1,0);
        if(dp[1][0]>dp[1][1])
            cout<<dp[1][1];
        else   
            cout<<dp[1][0];

        return 0;
        

    }