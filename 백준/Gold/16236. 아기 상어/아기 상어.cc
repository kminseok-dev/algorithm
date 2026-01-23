#include<bits/stdc++.h>

#define X first
#define Y second 

using namespace std;

typedef pair<int,pair<int,int>> Node;
typedef priority_queue<Node,vector<Node>,greater<Node>> PQ;

int n,cnt,weight = 2;
int sea[22][22];
int dist[22][22];
PQ bfs(pair<int,int> pos){
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};

    memset(dist,-1,sizeof(dist));

    PQ pq;
    queue<pair<int,int>> q;    
    q.push({pos.X,pos.Y});
    dist[pos.X][pos.Y] = 0;
    int maxDist = 2e9;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(maxDist <= dist[cur.X][cur.Y])continue;
        for(int i=0;i<4;i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            
            if(nx<1||ny<1||nx>n||ny>n)continue;
            if(sea[nx][ny]>weight)continue;
            if(dist[nx][ny] != -1)continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            
            if(sea[nx][ny]<weight&&sea[nx][ny]>0){
                if(maxDist == 2e9){
                    maxDist = dist[nx][ny];
                }
                pq.push({dist[nx][ny], {nx, ny}});
            }
            q.push({nx, ny});
        }
    }
    return pq;
}

int main(){
    pair<int,int> pos;
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> sea[i][j];
            if(sea[i][j]==9){
                pos = {i,j};
            }
        }
    }

    int ans = 0;
    
    while(1){
        PQ pq = bfs(pos);
        if(pq.empty())break;

        cnt++;
        if(cnt==weight){
            weight++;
            cnt = 0;
        }

        sea[pos.X][pos.Y] = 0;
        ans += pq.top().X;
        pos = pq.top().Y;
        sea[pos.X][pos.Y] = 9;
    }
    
    cout << ans;

    return 0;
}