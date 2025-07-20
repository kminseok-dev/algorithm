#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,m,ans=1e9;
int office[9][9];

vector<vector<vector<int>>> cctvDir = {
    {},
    {{0},{1},{2},{3}},
    {{0,2},{1,3}},
    {{0,1},{1,2},{2,3},{3,0}},
    {{0,1,2},{1,2,3},{2,3,0},{3,0,1}},
    {{0,1,2,3}}
};
struct cctv{
    int x;
    int y;
    int type;
};
vector<cctv>cctvs;

void watch(int x,int y,vector<int> dirs,int temp[9][9]){
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    for(auto dir : dirs){
        int nx = x;
        int ny = y;
        while(1){
            nx += dx[dir];
            ny += dy[dir];
            if(nx<1||ny<1||nx>n||ny>m)break;
            if(temp[nx][ny]==6)break;
            if(temp[nx][ny]==0) temp[nx][ny] = 7;
        }
    }

}


void dfs(int idx,int office_rep[9][9]){

    if(idx == cctvs.size()){
        int cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(office_rep[i][j]==0)
                    cnt++;
            }
        }
        
        ans = min(ans,cnt);
        return;
    }

    int x = cctvs[idx].x; 
    int y = cctvs[idx].y;
    int type = cctvs[idx].type;
    for(auto dir : cctvDir[type]){
        int temp[9][9];
        memcpy(temp,office_rep,sizeof(temp));
        watch(x,y,dir,temp);
        dfs(idx+1,temp);
    }
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >>office[i][j];
            if(office[i][j]>0&&office[i][j]<6) cctvs.push_back({i,j,office[i][j]});
        }
    }
    dfs(0,office);
    cout<<ans;
    
}