#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<vector<pair<int,int>>> adj(300001);
int d[20001];

int main(){
    int n,u,v,e,w;
    int start;

    fill(d,d+20001,2e9);

    cin >> n >> e >> start;

    for(int i=1;i<=e;i++){
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    d[start] = 0;
    pq.push({d[start],start});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(d[cur.Y]!=cur.X)continue;

        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y] + nxt.X)continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }

    }
    
    for(int i=1;i<=n;i++){
        if(d[i] == 2e9){
            cout<< "INF"<<'\n';
            continue;
        }
        cout << d[i] << '\n';
    }
    

    
}
