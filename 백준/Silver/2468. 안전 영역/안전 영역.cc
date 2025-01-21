#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int height[101][101];
bool visited[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int> >q;
int n,h;

    
    

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int ansmax=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> height[i][j];
            h = max(h,height[i][j]);
        }
    }
    int k = h+1;
    
    while(k>1){
        k--;
        int ans = 0;
        while(!q.empty()) q.pop();
        for(int i=0;i<n;i++)for(int j=0;j<n;j++) visited[i][j] = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n;j++){
                if(height[i][j]>k&&!visited[i][j]){
                    q.push(make_pair(i,j));
                    visited[i][j] = true;
                    ans++;
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
                            if(height[nx][ny]>k && visited[nx][ny]==false) {
                                visited[nx][ny] = true;
                                q.push(make_pair(nx,ny));
                            }
                            
                        }
                        
                    }
                }
            }
        }
        ansmax = max(ans,ansmax);
        
    }
    
    cout<<ansmax;;
    return 0;
}
    
   