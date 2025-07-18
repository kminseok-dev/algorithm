#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int n,m,ans;
int lab[9][9];
int lab_rep[9][9];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pair<int,int>> blank;
vector<pair<int,int>> wall;
vector<bool>visited;

void bfs(queue<pair<int,int>> q){

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<1||ny<1||nx>n||ny>m)continue;
            if(lab_rep[nx][ny]!=0)continue;
            lab_rep[nx][ny] = 2;
            q.push({nx,ny});
        }
 
    }
    return;
}

int safetySection(){
    int cnt = 0;
    queue<pair<int,int>> q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            lab_rep[i][j] = lab[i][j];
            if(lab[i][j] == 2) q.push({i,j});
        }
    }

    for(int i=0;i<3;i++){
        lab_rep[wall[i].first][wall[i].second] = 1;
    }

    bfs(q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(lab_rep[i][j]==0){
                cnt++;
            }
        }
    }
    return cnt;
}

void setWall(int idx,int k){
    if(k==3) {
        ans = max(ans,safetySection());
        return;
    }
    for(int i=idx;i<blank.size();i++){
            wall.push_back(blank[i]);
            // visited[i] = true;
            setWall(i+1,k+1);
            // visited[i] = false;
            wall.pop_back();
        
    }
}


int main(){

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> lab[i][j];
            if(lab[i][j]==0)blank.push_back({i,j});
           
        }
    }
    setWall(0,0);
    cout<<ans;


}