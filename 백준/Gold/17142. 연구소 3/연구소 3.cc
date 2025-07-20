#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,ans=1e9;
int lab[51][51];
int lab_rep[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int>> canPutVirus;
vector<pair<int,int>> virus;

void bfs(queue<pair<int,int>> q){

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<1||ny<1||nx>n||ny>n)continue;
            if(lab_rep[nx][ny]==-2)continue;
            if(lab_rep[nx][ny]>=0)continue;
            if(lab_rep[nx][ny]==-1){
                lab_rep[nx][ny] = 0;
                q.push({nx,ny});
                
            }
            lab_rep[nx][ny] = lab_rep[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }
}

int spreadVirus(){
    int result = 0;
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            lab_rep[i][j] = lab[i][j];
        }
    }
    for(int i=0;i<m;i++){
        lab_rep[virus[i].first][virus[i].second] = 0;
        q.push(virus[i]);
    }
    bfs(q);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(lab[i][j]==-3&&lab_rep[i][j]<0){
                
                return 1e9;
            }
            if(lab[i][j]==-3)result = max(result,lab_rep[i][j]);
        }
    }
    
    return result;


}
void setVirus(int idx,int k){
    if(k==m){
        ans = min(ans,spreadVirus());
    }
    
    for(int i=idx;i<canPutVirus.size();i++){
        virus.push_back({canPutVirus[i]});
        setVirus(i+1,k+1);
        virus.pop_back();
    }
}
int main(){
    int a;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a;
            if(a==2){
                lab[i][j] = -1;
                canPutVirus.push_back({i,j});
            }
            else if(a==1){
                lab[i][j] = -2;
            }
            else{
                lab[i][j] = -3;
            }
        }
    }
    setVirus(0,0);
    if(ans == 1e9) cout<<-1;
    else cout<<ans;



}