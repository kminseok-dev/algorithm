#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int map[1003][1003];
int dist[1003][1003][2];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n,m;
string road;
bool visited[1003][1003][2];
//visited[x][y][0] : 벽을 깨지 않은 상태에서 도달했는지
//visited[x][y][1] : 벽을 깬 상태에서 도달했는지
struct Node{
    int x,y;
    bool flag;
};

int bfs(){
    queue<Node> q;
    q.push({1,1,false});
    visited[1][1][0] = true;
    dist[1][1][0] = 1;
    
    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        
        if(cur.x == n && cur.y == m){
            return dist[n][m][cur.flag];
            
        }

        for(int i=0;i<4;i++){
            int nx = cur.x+ dx[i];
            int ny = cur.y + dy[i];
            if(nx<1||ny<1||nx>n||ny>m)continue;
            if(map[nx][ny]==0){
                if(visited[nx][ny][cur.flag])continue;
                visited[nx][ny][cur.flag] = true;
                dist[nx][ny][cur.flag] = dist[cur.x][cur.y][cur.flag] + 1;
                q.push({nx,ny,cur.flag});
            }
            else{
                if(!cur.flag&&!visited[nx][ny][1]){
                    visited[nx][ny][1] = true;
                    dist[nx][ny][1] = dist[cur.x][cur.y][cur.flag] + 1;
                    q.push({nx,ny,true});

                }
            }        
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> road;
        for(int j=1;j<=m;j++){
            map[i][j] = road[j-1] - '0';
        }
    }
    
    cout<< bfs();
    return 0;
    
   


}