#include<bits/stdc++.h>
#include<algorithm>

#define X first
#define Y second 

using namespace std;

int n,cnt,weight = 2;
int sea[22][22];

priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;


void bfs(pair<int,int> pos){

    int dist[22][22];    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};

    fill(&dist[0][0],&dist[21][22],-1);

    pq = priority_queue<pair<int,pair<int,int>>,
                vector<pair<int,pair<int,int>>>,
                    greater<pair<int,pair<int,int>>>>();

    queue<pair<int,int>> q;    
    q.push({pos.X,pos.Y});
    dist[pos.X][pos.Y] = 0;
    int maxDist = 2e9;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(maxDist <= dist[cur.X][cur.Y])continue;
        for(int i=0;i<4;i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx<1||ny<1||nx>n||ny>n)continue;
            if(sea[nx][ny]>weight)continue;
            if(dist[nx][ny]==-1&&sea[nx][ny]<weight&&sea[nx][ny]>0){
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                maxDist = dist[nx][ny];
                pq.push({dist[nx][ny],{nx,ny}});
                q.push({nx,ny});
            }
            else if(dist[nx][ny]==-1&&sea[nx][ny]<=weight){
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                q.push({nx,ny});
            }
        }
    }


       
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
        bfs(pos);
        if(pq.empty())break;
        cnt++;
        if(cnt==weight){
            weight++;
            cnt = 0;
        }
        sea[pos.X][pos.Y] = 0;
        ans += pq.top().X;
        pos = {pq.top().Y.X,pq.top().Y.Y};
        sea[pos.X][pos.Y] = 9;
        

    }
    
    cout << ans;

    
    

    
    
    
}