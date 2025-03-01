#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
int n,m,v;
bool visited[1001];
// void dfs(){
//     stack<int> s;
//     s.push(v);
//     while(!s.empty()){
//         int cur = s.top();
//         s.pop();
//         if(visited[cur]) continue;
//         visited[cur]=true;
//         cout << cur <<' ';
//         for(int i=0;i<adj[cur].size();i++){
//             int nxt = adj[cur][adj[cur].size()-1-i];
//             if(visited[nxt])continue;
//             s.push(nxt);
//         }
//     }
//     cout<<'\n';
    
// }
void dfs(int cur){
    visited[cur] = true;
    cout<<cur<<" ";
    for(int nxt : adj[cur]){
        if(visited[nxt])continue;
        dfs(nxt);
    }

}
void bfs(){
    queue<int>q;
    q.push(v);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(visited[cur]) continue;
        visited[cur]=true;
        cout << cur <<' ';
        for(int i=0;i<adj[cur].size();i++){
            int nxt = adj[cur][i];
            if(visited[nxt]) continue;
            q.push(nxt);
        }
    }
}
int main(){
    cin >> n >> m >> v;
    while(m--){
        int u,k;
        cin >> u >> k;
        adj[u].push_back(k);
        adj[k].push_back(u);
    }
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    dfs(v);
    cout<<'\n';
    fill(visited+1,visited+n+1,false);
    bfs();
}