#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

vector<vector<int>> field(50,vector<int>(50));    
vector<vector<bool>>isvisited(50,vector<bool>(50));

int m,n,num;

void bfs(int x,int y){
    queue<pair<int,int>> point;
    point.push({x,y});
    while(!point.empty()){
        pair<int,int> cur = point.front();
        point.pop();
        isvisited[cur.second][cur.first] = true;
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0||ny<0||nx>=m||ny>=n)continue;
            if(field[ny][nx]==0||isvisited[ny][nx]==true)continue;
            isvisited[ny][nx] = true;
            point.push({nx,ny});

        }
    }   
}
    

void solve(){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!isvisited[i][j]&&field[i][j]){
                bfs(j,i);
                cnt++;        
            }        
        }        
    }
    cout<<cnt<<'\n';
    
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T-->0){
        cin >> m >> n >> num;
        while(num-->0){
            int x,y;
            cin>>x>>y;
            field[y][x] = 1;
        }
        solve();
        for(int i=0;i<field.size();i++){
            fill(field[i].begin(),field[i].end(),0);
            fill(isvisited[i].begin(),isvisited[i].end(),0);
        }    
    }
    return 0;
}