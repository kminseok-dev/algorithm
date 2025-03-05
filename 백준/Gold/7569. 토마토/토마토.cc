#include <bits/stdc++.h>
#include <tuple>
#define FOR(i,j) for(ll i=1;i<=j;i++)
// #define mk_tp(i,j,k) make_tuple(i,j,k)
#define Z get<0>
#define X get<1>
#define Y get<2>
typedef long long ll;

using namespace std;

ll board[101][101][101];
ll dist[101][101][101];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int M,N,H;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<tuple<ll,ll,ll> > q;
    cin >> M >> N >> H;
    FOR(i,H){
        FOR(j,N){
            FOR(k,M){
                cin >> board[i][j][k];
                if(board[i][j][k] == 1)q.push(make_tuple(i,j,k));
                else if(board[i][j][k] == 0)dist[i][j][k] = -1;
                
            }
        }
    }
    
    while(!q.empty()){
        tuple<ll,ll,ll> cur = q.front();
        q.pop();
        for(ll i=0;i<6;i++){
            ll nx = X(cur) + dx[i];
            ll ny = Y(cur) + dy[i];
            ll nz = Z(cur) + dz[i];
            if(nx<1 || ny<1 || nz<1 || nx>N || ny>M || nz>H || board[nz][nx][ny]==-1||dist[nz][nx][ny]>=0) continue;
            dist[nz][nx][ny] = dist[Z(cur)][X(cur)][Y(cur)]+1;
            q.push(make_tuple(nz,nx,ny));
        }
    }
    ll ans = 0;
    FOR(i,H){
        FOR(j,N){
            FOR(k,M){
                //cout<<dist[i][j][k]<<' ';
                if(dist[i][j][k]==-1){cout<<-1;return 0; }
                ans = max(ans, dist[i][j][k]);
            }
           // cout<<'\n';
        }       
        //cout<<'\n';
    }
    cout<<ans;
    return 0;
}

