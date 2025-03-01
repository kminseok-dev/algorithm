#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1001];
bool visited[1001];
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int num = 0;
    for(int i=1;i<=n;i++){
        if(visited[i]){continue;}
        num++;
        queue<int> q;
        visited[i] = true;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nex : adj[cur]){
                if(!visited[nex]){
                    q.push(nex);
                    visited[nex] = true;
                    
                }
            }
        }
    }
    cout<<num;
        
}