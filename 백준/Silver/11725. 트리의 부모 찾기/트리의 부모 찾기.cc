#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj(100001);
int tree[100001];
bool visited[100001];

void dfs(int k){
    visited[k] = true;
    for(int i=0;i<adj[k].size();i++){
        int child = adj[k][i];
        if(!visited[child]){
            tree[child] = k;
            dfs(child);
        }    
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,v,u;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(1);
    for(int i=2;i<=n;i++){
        cout<<tree[i]<<'\n';
    }
}