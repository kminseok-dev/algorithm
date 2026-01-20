#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

vector<pair<int,int>> bus[1005];
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
int dist[1005];
int pre[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    int u,v,w;
    int str,dst;
    
    cin >> n >> m;
    fill(dist,dist+n+1,2e9);

    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        bus[u].push_back({w,v});
    }
    
    cin >> str >> dst;

    q.push({0,str});
    dist[str] = 0;

    while(!q.empty()){
        auto cur = q.top(); q.pop();
        if(dist[cur.Y] != cur.X)continue;
        for(auto nxt : bus[cur.Y]){
            if(dist[nxt.Y] <= dist[cur.Y] + nxt.X)continue;
            dist[nxt.Y] = dist[cur.Y] + nxt.X;
            q.push({dist[nxt.Y],nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }
    
    cout << dist[dst] << '\n';
    
    int city = dst;
    vector<int> path;
    
    while(city!=0){
        path.push_back(city);
        city = pre[city];
        
    }
    cout << path.size() << '\n';
    reverse(path.begin(),path.end());
    for(int a : path){
        cout << a << ' ';
    }

    
}