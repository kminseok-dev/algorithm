#include <bits/stdc++.h>

using namespace std;
 bool visited[55][55];
 

vector<pair<int,int>> BFS(int x, int y, int n, int L, int R, int arr[55][55]){
    
    vector<pair<int,int>> v;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    queue<pair<int,int>> q;
    q.push({x,y});
    v.push_back({x,y});
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        visited[cur.first][cur.second] = true;
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<1||ny<1|nx>n||ny>n)continue;
            if(visited[nx][ny] == true)continue;
            int gap = abs(arr[cur.first][cur.second]-arr[nx][ny]);
            if(gap>=L&&gap<=R){
                visited[nx][ny] = true;
                v.push_back({nx,ny});
                q.push({nx,ny});
            }
        }
    }
    return v;

}
int main(){
    int n,L,R;
    int arr[55][55];
    
    cin >> n >> L >> R;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    int cnt = 0;

    while(1){
        bool move = false;
        memset(visited,false,sizeof(visited));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int tot_people = 0;
                if(!visited[i][j]){
                    auto v = BFS(i,j,n,L,R,arr);
                    if(v.size()<=1)continue;
                    
                    move = true;
                    for(auto i:v){
                        tot_people += arr[i.first][i.second];
                    }
                    tot_people /= v.size();
                    for(auto i : v){
                        arr[i.first][i.second] = tot_people;
                    }
                    

                    
                }
            }
        }
        if(!move) break;
        cnt++;
    }
    cout<<cnt;

    

    return 0;
    

}