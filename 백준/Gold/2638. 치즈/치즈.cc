#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;

int paper[105][105];
int visited[105][105];
int n,m;

int bfs(){

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int count = 0;
    
    fill(&visited[0][0],&visited[104][105],0);
    visited[0][0] = 1;

    queue<pair<int,int>> q;
    q.push({0,0});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx<0||ny<0||nx>n||ny>m)continue;
            if(paper[nx][ny]==1){
                visited[nx][ny]++;
                if(visited[nx][ny]>=2){
                    paper[nx][ny] = 0;
                    count++;
                }
            }
            else if(paper[nx][ny]==0&&!visited[nx][ny]){
                visited[nx][ny]++;
                q.push({nx,ny});
            }
        }
    }
    
    return count;
     
}
int main(){
    
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> paper[i][j];
        }
    }
    
    int ans = -1;
    int count = 0;
    while(1){
        ans++;
        count = bfs();
        if(count==0)break;
    }

    cout << ans;
}