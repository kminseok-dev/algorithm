#include<bits/stdc++.h>
using namespace std;
int arr[1003][1003];
vector<vector<bool>> valid(1003,vector<bool>(1003,true));
void search(int n, int m, pair<int,int> start){
    queue<pair<int,int>> sq;
    int dirx[4] = {1,0,-1,0};
    int diry[4] = {0,-1,0,1};
    sq.push(start);
    while(!sq.empty()){
        pair<int,int> cur = sq.front();
        valid[cur.first][cur.second] = false;
        sq.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dirx[i];
            int ny = cur.second + diry[i];
            if(nx<1||ny<1||nx>n||ny>m)continue;
            if(valid[nx][ny]==false)continue;
            arr[nx][ny] = arr[cur.first][cur.second] + 1;
            valid[nx][ny] = false;
            sq.push({nx,ny});
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,a;
    pair<int,int> start;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a;
            if(a==0){
                valid[i][j] = false;
            }
            else if(a==2){
                start = {i,j};
            }
            
        }
    }
    search(n,m,start);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(valid[i][j]==false)
                cout<<arr[i][j]<<' ';
            else
                cout<<-1<<' '; 

        }
        cout<<'\n';
    }
    return 0; 
}