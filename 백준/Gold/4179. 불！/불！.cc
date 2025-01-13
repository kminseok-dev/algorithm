#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
char board[1001][1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int  main(){
    string boardString;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    
    queue<pair<int,int> > fire;
    queue<pair<int,int> > jh;
    for(int i=0; i<n; i++){
        fill(dist1[i],dist1[i]+m,-1);
        fill(dist2[i],dist2[i]+m,-1 );
    }
    for(int i=0; i<n; i++){
        cin >> boardString ;
        for(int j=0;j<m;j++){
            board[i][j] = boardString[j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'J'){
                jh.push(make_pair(i,j));
                dist1[i][j] = 0;
            }
            if(board[i][j] == 'F'){
                fire.push(make_pair(i,j));
                dist2[i][j] = 0;
            }
        }
    }
    while(!fire.empty()){
        auto cur = fire.front( );
        fire.pop( );
        for(int dis=0;dis<4;dis++){
            int nx = cur.X + dx[dis];
            int ny = cur.Y + dy[dis];
            if(nx<0 ||nx>=n || ny<0 || ny>=m)continue;
            if(board[nx][ny]== '#' || dist2[nx][ny] >=0)continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            fire.push(make_pair(nx,ny));
        }
    }
    
    while(!jh.empty()){
        auto cur = jh.front( );
        jh.pop( );
        for(int dis=0;dis<4;dis++){
            int nx = cur.X + dx[dis];
            int ny = cur.Y + dy[dis];
            
            if(nx<0||nx>=n||ny<0||ny>=m){
                cout << dist1[cur.X][cur.Y]+1; 
                return 0;
            }
            if(dist1[nx][ny]>=0||board[nx][ny]=='#')continue;
            
            if(dist2[nx][ny]!=-1 && dist2[nx][ny]<=dist1[cur.X][cur.Y]+1)continue;
            
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            jh.push(make_pair(nx,ny));
        }

    }
    cout<<"IMPOSSIBLE";
}

    
    
    