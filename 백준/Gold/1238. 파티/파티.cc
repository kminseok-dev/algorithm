#include<iostream>
#include<vector>
#include<queue>

#define X first
#define Y second

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<vector<pair<int,int>>> reverseTree(10002);
vector<vector<pair<int,int>>> tree(10002);
int backDist[1002];
int dist[1002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m,x;
    int u,v,w;
    fill(backDist,backDist+1001,2e9);
    fill(dist,dist+1001,2e9);

    cin >> n >> m >> x;

    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        reverseTree[u].push_back({w,v});
        tree[v].push_back({w,u});
    }
    
    backDist[x] = 0;
    dist[x] = 0;

    pq.push({0,x});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        
        if(backDist[cur.Y]!=cur.X)continue;
        for(auto nxt : reverseTree[cur.Y]){
            if(backDist[nxt.Y]<=backDist[cur.Y] + nxt.X)continue;
            backDist[nxt.Y] = backDist[cur.Y] + nxt.X;
            pq.push({backDist[nxt.Y],nxt.Y});
        }
    }
    
    pq = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();

    pq.push({0,x});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        
        if(dist[cur.Y]!=cur.X)continue;
        for(auto nxt : tree[cur.Y]){
            if(dist[nxt.Y]<=dist[cur.Y] + nxt.X)continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            pq.push({dist[nxt.Y],nxt.Y});   
        }
    }

    int result = 0;
    for(int i=1;i<=n;i++){
        result = max(result,dist[i] + backDist[i]);
    }
    cout << result;
    
}