#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;


struct fireBall{
    int r,c,m,d,s;
};

int N,M,K;

queue<fireBall> fBox;
vector<fireBall>world[55][55];
vector<pair<int,int>> dir = {
    {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}
};

queue<pair<int,int>> bfs(queue<fireBall>q){
    queue<pair<int,int>>pos;

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int nr = cur.r;
        int nc = cur.c;
        for(int i=1;i<=cur.s;i++){
            nr += dir[cur.d].X;
            nc += dir[cur.d].Y;
            if(nr<1||nc<1||nr>N||nc>N){
                if(nr<1)nr=N;
                else if(nr>N)nr = 1;
                if(nc<1)nc = N;
                else if(nc>N)nc = 1;
            }
        }
        world[nr][nc].push_back(cur);     
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(world[i][j].size()>=2)pos.push({i,j});
            else if(world[i][j].size()==1){
                fireBall fire = world[i][j][0];
                fire.r = i;
                fire.c = j;
                fBox.push(fire);
            }
        }
    }
    
    return pos;   
}
void seperate(queue<fireBall>q){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            world[i][j].clear();
        }
    }
    fBox = queue<fireBall>();
    queue<pair<int,int>> que = bfs(q);

    
    
    
    while(!que.empty()){
        bool flag;
        int cnt=0;
        fireBall sfb = {0,0,0,0,0};
        
        auto cur = que.front();
        sfb.r = cur.X;
        sfb.c = cur.Y;
        que.pop();
        if(world[cur.X][cur.Y][0].d%2==0) flag = true;
        else flag = false;

        for(int i=0;i<world[cur.X][cur.Y].size();i++){
            sfb.m += world[cur.X][cur.Y][i].m;
            sfb.s += world[cur.X][cur.Y][i].s;
            if(flag){
                if(world[cur.X][cur.Y][i].d%2!=0)cnt=1;
            }
            else{
                if(world[cur.X][cur.Y][i].d%2==0)cnt=1;
            }
        }
        sfb.m /= 5;
        if(sfb.m == 0)continue;
        sfb.s /= world[cur.X][cur.Y].size();
        int dir = 0;
        if(cnt==1){
            dir = 1;
        }
        for(int i=0;i<4;i++){
            sfb.d = dir;
            dir += 2;
            fBox.push(sfb);
        }
    }
    
}

int main(){
    queue<fireBall> q;
    fireBall fb;

    cin >> N >> M >> K;

    for(int i=1;i<=M;i++){
        cin >> fb.r >> fb.c >> fb.m >> fb.s >> fb.d;
        q.push(fb);
    }
    while(K--){
        seperate(q);
        q = fBox;
        
    }
    int ans = 0;
    while(!q.empty()){
        auto ball = q.front();
        q.pop();
        ans += ball.m;
    }
    cout << ans;
    return 0;
}