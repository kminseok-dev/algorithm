#include <bits/stdc++.h>
#define mk(i,j) make_pair(i,j)
#define X first
#define Y second
using namespace std;
bool vis[10001];
void bfs(int start, int end){
    queue<pair<int,string> > q;
    q.push(mk(start, ""));
    
    while(!q.empty()){
        int k = q.front().X;
        string s = q.front().Y;
        q.pop();
        vis[k] = true;
        if(k==end){
            cout<<s<<'\n';
            return;
        }
        int D,S,L,R;
        D = (2*k)%10000;
        if(!vis[D]){
            vis[D] = true;
            q.push(mk(D, s + "D"));
        }
        S = k-1<0 ? 9999 : k-1;
        if(!vis[S]){
            vis[S] = true;
            q.push(mk(S, s + "S"));
        }
        L = (k%1000)*10+k/1000;
        if(!vis[L]){
            vis[L] = true;
            q.push(mk(L, s + "L"));
        }
        R = (k%10)*1000+k/10;
        if(!vis[R]){
            vis[R] = true;
            q.push(mk(R, s + "R"));
        }
    }
        
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int start, end;
        cin>>start>>end;
        memset(vis, false, sizeof(vis));
        bfs(start, end);

    }
    return 0;
}


