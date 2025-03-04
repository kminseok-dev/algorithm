#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int board[1001][1001];
int dist[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int  main(){
    queue<pair<int,int> >q;
    int n,m;
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j]==1)q.push(make_pair(i,j));
            if(board[i][j]==0)dist[i][j] = -1;            
        }
    }
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int dis=0;dis<4;dis++){
            int nx = cur.X + dx[dis];
            int ny = cur.Y + dy[dis];
            if(nx<0 || nx>=n||ny<0 || ny>=m)continue;
            if(dist[nx][ny]>=0||board[nx][ny]==-1)continue;
            q.push(make_pair(nx,ny));
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]==-1){cout<<-1<<'\n';return 0;}
            ans = max(ans,dist[i][j]);
        }
    }
    cout<<ans;
}

    
    