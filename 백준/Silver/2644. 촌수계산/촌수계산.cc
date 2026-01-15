#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> tree(105);
bool visited[105];
queue<int> q;
int dist[105];

int main(){

    int n,m,x,y;
    int u,v;
    
    cin >> n >> u >> v >> m;

    for(int i=1;i<=m;i++){
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    q.push(u);
    visited[u] = true;
    dist[u] = 0;

    while(!q.empty()){

        int cur = q.front(); q.pop();

        if(cur == v){
            cout << dist[cur];
            return 0;
        }
        for(int nxt : tree[cur]){
            if(!visited[nxt]){
                visited[nxt] = true;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    cout << -1;
    return 0;

}