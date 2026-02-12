#include<bits/stdc++.h>

#define X first
#define Y second

using namespace std;


struct fireBall{
    int r,c,m,s,d;
};

int N,M,K;

queue<fireBall> fBox;
map<pair<int,int>,vector<fireBall>>world;
vector<pair<int,int>> dir = {
    {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}
};

void moveFb(queue<fireBall>& q){
    world.clear();

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int nr = cur.r + cur.s * dir[cur.d].X;
        int nc = cur.c + cur.s * dir[cur.d].Y;
        
        nr = ((nr-1) % N + N) % N + 1;
        nc = ((nc-1) % N + N) % N + 1;

        cur.r = nr;
        cur.c = nc;

        world[{nr,nc}].push_back(cur);     
    }
}

void seperateFb(){
    fBox = queue<fireBall>();

    for(auto& it : world){
        if(it.Y.size()>=2){
            fireBall sfb = {it.X.X,it.X.Y,0,0,0};
            bool flag = true;
            int parity = it.Y[0].d % 2;

            for(auto& fire : it.Y){
                sfb.m += fire.m;
                sfb.s += fire.s;   
                if(fire.d%2 != parity)flag = false;
            }
            
            sfb.m /= 5;
            if(sfb.m == 0)continue;
            sfb.s /= it.Y.size();

            int startD = flag ? 0 : 1;
        
            for(int d=startD;d<=7;d+=2){
                sfb.d = d;
                fBox.push(sfb);
            }    
        }
        else if(it.Y.size()==1){
            fBox.push(it.Y[0]);
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
        moveFb(q);
        seperateFb();
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